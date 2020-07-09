#include "cStreamingService.h"
#include "cBaseDatos.h"
#include <stdlib.h>

bool contraseniaSegura(string password);
//obtiene la hora actual con un formato de numero año-mes-dia-hora-minutos-segundos
long long getTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);  //se debe calibrar-->experimenta un desfazaje
    long long date = (1900 + ltm->tm_year) * 10000 + (1 + ltm->tm_mon) * 100 + (ltm->tm_mday);
    long long time = (ltm->tm_hour) * 10000 + (ltm->tm_min) * 100 + (1 + ltm->tm_sec);
    return date * 1000000 + time;
}

bool checkServiceAvailability(string paisUsuario, vector<string> PaisesProhibidos) {
    //pasamos las dos a un unico formato (lowercase) y las comparamos
    std::for_each(paisUsuario.begin(), paisUsuario.end(), [](char& c) {
        c = ::tolower(c);
    });
    
    for (int i = 0;i < PaisesProhibidos.size();i++) {
        std::for_each(PaisesProhibidos[i].begin(), PaisesProhibidos[i].end(), [](char& c) {
            c = ::tolower(c);
        });
        if (paisUsuario.compare(PaisesProhibidos[i])==0) {//significa que el pais del usuario esta en la lista prohibida
            cout << "Lo sentimos CONTENIDO NO DISPONIBLE en su region :(" << endl;
            return false;
        }
    }
    return true;
}

pair<long long, string> cStreamingService::SELECCION(string paisUsuario) {//retorna el timestamp(timepo pasado en el servicio
    cout << "ESTA INTERESADO EN ALGUNO?..." << endl;
    cout << "Por favor INGRESE el nombre del SERVICIO" << endl;
    string str;//FIX DEL BUG 1.0 parche
    getline(cin, str);
    string nombre;  
    getline(cin, nombre);
    //el servicio mencionado existe?
    cServicio* servicio = BuscarServicio(nombre);
    bool acceso = checkServiceAvailability(paisUsuario, servicio->getPaisesProhibidos());//checkeamos que el usuario pueda ver el contenido en su pais
    if (servicio == NULL || acceso == false) return make_pair(-1, "");
    cPeliculas* pel = dynamic_cast<cPeliculas*>(servicio);
    cJuegos* jug = dynamic_cast<cJuegos*>(servicio);
    cAudio* aud = dynamic_cast<cAudio*>(servicio);
    long long inicio = getTime();
    if (pel) {
        //en la medida de tener un registro del tiempo que el 
        //usuario interactuo con el servicio, ademas de con que 
        //servicio y quien es el usuario se implemneta un LOG
        //que se registrara al final de cada operacion
        //-cierre de secion de un usuario-->tiempo en que se estubo en la plataforma
        //-al final de la interaccion con un servicio
        //se debe tener registro de cuando se inicia la interaccion y de cuando 
        //se finaliza, para obtner la duracion TOTAL
        //COMO PUNTO DE partida el cronometro se inciara cuando se seleccione
        //el servicio, y se finaliza cuando se apague el servicio-->se puede crear el LOG
        int option = 0;
        while (true) {
            cout << "OPCIONES" << endl;
            cout << "1. Descargar" << endl;
            cout << "2. Iniciar" << endl;
            cout << "3. Pausar" << endl;
            cout << "4. Retroceder" << endl;
            cout << "5. Adelantar" << endl;
            cout << "6. Grabar" << endl;
            cout << "7. Apagar" << endl;
            cin >> option;
            switch (option) {
            case 1:
                pel->descargar();
                break;
            case 2:
                pel->iniciar();
                break;
            case 3:
                pel->pausar();
                break;
            case 4:
                pel->backFoward();
                break;
            case 5:
                pel->fastFoward();
                break;
            case 6:
                pel->record();
                break;
            case 7:
                pel->apagar();
                return make_pair((getTime() - inicio), pel->getCodigo());

            default:
                cout << "NO SE HA INTRODUCIDO UNA OPCION CORRECTA";
            }
        }
    }
    else if (jug) {
        int option = 0;
        while (true) {
            cout << "OPCIONES" << endl;
            cout << "1. Descargar" << endl;
            cout << "2. Iniciar" << endl;
            cout << "3. Pausar" << endl;
            cout << "4. Guardar" << endl;
            cout << "5. Comandos" << endl;
            cout << "6. Apagar" << endl;
            cin >> option;
            switch (option) {
            case 1:
                jug->descargar();
                break;
            case 2:
                jug->iniciar();
                break;
            case 3:
                jug->pausar();
                break;
            case 4:
                jug->guardar();
                break;
            case 5:
                jug->Comandos();
                break;
            case 6:
                jug->apagar();
                return make_pair((getTime() - inicio), jug->getCodigo());

            default:
                cout << "NO SE HA INTRODUCIDO UNA OPCION CORRECTA";
            }
        }
    }
    else if (aud) {
        int option=0;
        while (true) {
            cout << "OPCIONES" << endl;
            cout << "1. Descargar" << endl;
            cout << "2. Iniciar" << endl;
            cout << "3. Pausar" << endl;
            cout << "4. Retroceder" << endl;
            cout << "5. Adelantar" << endl;
            cout << "6. Grabar" << endl;
            cout << "7. Apagar" << endl;
            cin >> option;
            switch (option) {
            case 1:
                aud->descargar();
                break;
            case 2:
                aud->iniciar();
                break;
            case 3:
                aud->pausar();
                break;
            case 4:
                aud->backFoward();
                break;
            case 5:
                aud->fastFoward();
                break;
            case 6:
                aud->record();
                break;
            case 7:
                aud->apagar();
                return make_pair((getTime() - inicio), aud->getCodigo());

            default:
                cout << "NO SE HA INTRODUCIDO UNA OPCION CORRECTA";
            }
        }
    }
    
    cout << "EL SERVICIO INTRODUCIDO NO HA SIDO ENCONTRADO"<<endl;
    return make_pair(-1, "");
}


cPersona* cStreamingService::inicioSesion() {
    string usuario;
    string contrasenia;
    cout << "Ingrese el USUARIO" << endl;
    cin >> usuario;
    cout << "Ingrese la CONTRASEÑA" << endl;
    cin >> contrasenia;

    cPersona* per = cBaseDatos::BuscarPersona(usuario);
    if (per) {//existe el usuario?
        //es igual su contraseña a la introducida?
        if (per->compararContrasenia(contrasenia)) {
            per->setOnline();  //SE CAMBIA EL STATUS ONLINE A TRUE
            return per;
        }else
        {
            return NULL;
        }
    }
    else {
        return NULL;
    }
}

void cStreamingService::INTERACCION() {
	int x=-1,w,p, cont=0, confirmation;
SESION:
    cPersona* per = inicioSesion();
    cUsuario* user = dynamic_cast<cUsuario*>(per);
    cAdministrador* adm = dynamic_cast<cAdministrador*>(per);
    if (user) {//se dividen las opciones para los usuarios y los administradores
        cout << "SEA BIENVENIDO " << user->getNombre()<< endl;
        while (x != 0) {
            cout << "°°°°°°°°MENU°°°°°°°°" << endl;
            cout << "1. PELICULAS" << endl;
            cout << "2. JUEGOS" << endl;
            cout << "3. AUDIOS" << endl;
            cout << "4. TODOS" << endl;
            cout << "5. INGRESAR CON OTRO USUARIO" << endl;
            cout << "0. APAGAR" << endl;
            cin >> x;
            if (x == 0) {
                cout << "ESTA SEGURO QUE QUIERE APAGAR EL DISPOSITIVO?" << endl;
                cout << "0. NO" << endl;
                cout << "1. SI" << endl;
                cin >> confirmation;
                if (confirmation) {
                    //se cambia el status online a false
                    user->setOnline();
                    return;
                }
                cout << "°°°°°°°°MENU°°°°°°°°" << endl;
                cout << "1. PELICULAS" << endl;
                cout << "2. JUEGOS" << endl;
                cout << "3. AUDIOS" << endl;
                cout << "4. TODOS" << endl;
                cin >> x;
            }
            {
                switch (x) {
                case 1:
                    cout << "CATEGORIAS:" << endl;
                    cout << "1. ACCION" << endl;
                    cout << "2. AVENTURA" << endl;
                    cout << "3. COMEDIA" << endl;
                    cout << "4. TERROR" << endl;
                    cout << "5. MISTERIO" << endl;
                    cout << "6. DOCUMENTAL" << endl;
                    cout << "7. AMOR" << endl;
                    cout << "8. TODOS" << endl;
                    cin >> w;
                    switch (w) {
                    case 1:
                    {
                        ListarCategoria<cPeliculas>(ePeliculas::accion);
                    }
                    case 2:
                        ListarCategoria<cPeliculas>(ePeliculas::aventura);
                        break;
                    case 3:
                        ListarCategoria<cPeliculas>(ePeliculas::comedia);
                        break;
                    case 4:
                        ListarCategoria<cPeliculas>(ePeliculas::terror);
                        break;
                    case 5:
                        ListarCategoria<cPeliculas>(ePeliculas::misterio);
                        break;
                    case 6:
                        ListarCategoria<cPeliculas>(ePeliculas::documental);
                        break;
                    case 7:
                        ListarCategoria<cPeliculas>(ePeliculas::amor);
                        break;
                    case 8:
                        ListarCategoria<cPeliculas>();
                        break;
                    }
                    if (w < 1 || w>8) {
                        cout << "LA OPCION INGRESADA NO ES CORRECTA :(" << endl;
                    }
                    break;
                case 2:
                    cout << "CATEGORIAS:" << endl;
                    cout << "1. AUTOS" << endl;
                    cout << "2. ARMAS" << endl;
                    cout << "3. MULTIJUGADOR" << endl;
                    cout << "4. ROPA" << endl;
                    cout << "5. DEPORTES" << endl;
                    cout << "6. TODOS:" << endl;
                    cin >> w;
                    switch (w) {
                    case 1:
                        ListarCategoria<cJuegos>(eJuegos::autos);
                        break;
                    case 2:
                        ListarCategoria<cJuegos>(eJuegos::armas);
                        break;
                    case 3:
                        ListarCategoria<cJuegos>(eJuegos::multijugador);
                        break;
                    case 4:
                        ListarCategoria<cJuegos>(eJuegos::ropa);
                        break;
                    case 5:
                        ListarCategoria<cJuegos>(eJuegos::deportes);
                        break;
                    case 6:
                        ListarCategoria<cJuegos>();
                        break;
                    }
                    if (w > 6 || w < 1) { cout << "LA OPCION INGRESADA NO ES CORRECTA :(" << endl; }
                    break;
                case 3:
                    cout << "CATEGORIAS:" << endl;
                    cout << "1. PODCAST" << endl;
                    cout << "2. CANCION" << endl;
                    cout << "3. AUDIOLIBRO" << endl;
                    cout << "4. TODOS" << endl;
                    cin >> w;
                    switch (w) {
                    case 1:
                        ListarCategoria<cAudio>(eAudio::podcast);
                        break;
                    case 2:
                        ListarCategoria<cAudio>(eAudio::cancion);
                        break;
                    case 3:
                        ListarCategoria<cAudio>(eAudio::audioLibro);
                        break;
                    case 4:
                        ListarCategoria<cAudio>();
                        break;
                    }
                    if (w > 4 || w < 1) {
                        cout << "LA OPCION INGRESADA NO ES CORRECTA :(" << endl;
                    }
                    break;
                case 4:
                {
                    cout <<'\t'<< '\t' << "TITULO" << std::setw(22) << "DURACION" <<"  "<<"CODIGO"<<endl;
                    ListarServicios();
                    break;
                }
                case 5:
                {
                    cont = 0;//reiniciamos el contador
                    goto SESION;
                }
                default:
                    if (x != 0) {
                        cout << "NINGUNA DE LAS OPCIONES esta disponible" << endl;
                        cout << "porfavor pruebe otra vez" << endl;
                    }
                    break;
                }
                pair<long long, string> info = SELECCION(user->getPais()); //llamamos a seleccion que nos retorna
                long long timestamp = info.first; //el timepo que el usuario paso en un serivicio
                string codigo = info.second;//ademas del codigo del servicio que se utilizo
                string idUsuario = user->getID();
                if (codigo == "") {

                }
                else {
                    cLog* log = new cLog(idUsuario, codigo, timestamp);
                    cLogger::Registrar(log);
                }

            }
        }
    }
    else if (adm) {
        cout << "SEA BIENVENIDO "<<adm->getNombre() << endl;
        while (x != 0) {
            cout << "°°°°°°°°MENU°°°°°°°°" << endl;
            cout << "1. AGREGAR SERVICIO" << endl;
            cout << "2. ELIMINAR SERVICIO" << endl;
            cout << "3. BUSCAR SERVICIO" << endl;
            cout << "4. AGREGAR USUARIO" << endl;
            cout << "5. ELIMINAR USUARIO" << endl;
            cout << "6. ESTADISTICAS" << endl;
            cout << "7. INGRESAR CON OTRO USUARIO" << endl;
            cout << "0. APAGAR" << endl;
            cin >> x;
            switch (x) {
            case 1:
            {
                int l;
                cout << "INGRESE el tipo de servicio" << endl;
                cout << "1.Pelicula" << endl;
                cout << "2.Audio" << endl;
                cout << "3.Juego" << endl;
                cin >> l;
                if (l == 1) {
                    int duracion, categoria;
                    string nombre;
                    ePeliculas categ;
                    cout << "Ingrese la duracion de la pelicula" << endl;
                    cin >> duracion;
                    cout << "Ingrese el nombre de la pelicula" << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese la categoria de la pelicula" << endl;
                    cout << "1. Accion" << endl;
                    cout << "2. Aventura" << endl;
                    cout << "3. Comedia" << endl;
                    cout << "4. Terror" << endl;
                    cout << "5. Misterio" << endl;
                    cout << "6. Documental" << endl;
                    cout << "7. Amor" << endl;

                    cin >> categoria;
                    while (categoria > 7 || categoria < 1) {
                        cout << "La opcion escogida no es correcta" << endl;
                        cin >> categoria;
                    }
                    switch (categoria)
                    {
                    case 1:
                        categ = ePeliculas::accion;
                        break;
                    case 2:
                        categ = ePeliculas::aventura;
                        break;
                    case 3:
                        categ = ePeliculas::comedia;
                        break;
                    case 4:
                        categ = ePeliculas::terror;
                        break;
                    case 5:
                        categ = ePeliculas::misterio;
                        break;
                    case 6:
                        categ = ePeliculas::documental;
                        break;
                    case 7:
                        categ = ePeliculas::amor;
                        break;
                    }
                    string estudio;
                    cout << "Ingrese el estudio productor de la PELICULA" << endl;
                    getline(cin, estudio);
                    getline(cin, estudio);

                    cPeliculas* pel = new cPeliculas(duracion, nombre, categ, estudio);
                    AgregarServicio(pel);
                }
                else if (l == 2) {
                    int duracion, categoria;
                    string nombre, artista;
                    eAudio categ;
                    cout << "Ingrese la duracion del Audio" << endl;
                    cin >> duracion;
                    cout << "Ingrese la el nombre del Audio" << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese el nombre del artista" << endl;
                    getline(cin, artista);
                    cout << "Ingrese la categoria del Audio" << endl;
                    cout << "1. Podcast" << endl;
                    cout << "2. Cancion" << endl;
                    cout << "3. AudioLibro" << endl;
                    cin >> categoria;
                    while (categoria > 3 || categoria < 1) {
                        cout << "La opcion escogida no es correcta" << endl;
                        cin >> categoria;
                    }
                    switch (categoria)
                    {
                    case 1:
                        categ = eAudio::podcast;
                        break;
                    case 2:
                        categ = eAudio::cancion;
                        break;
                    case 3:
                        categ = eAudio::audioLibro;
                        break;

                    }
                    cAudio* aud = new cAudio(duracion, nombre, artista,categ);
                    AgregarServicio(aud);
                }
                else if (l == 3) {
                    int duracion, categoria;
                    string nombre, empresa;
                    eJuegos categ;
                    cout << "Ingrese la duracion del Juego" << endl;
                    cin >> duracion;
                    cout << "Ingrese el nombre deL Juego " << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese la empresa productora del Juego " << endl;
                    getline(cin, empresa);
                    cout << "Ingrese la categoria del Juego" << endl;
                    cout << "1. Autos" << endl;
                    cout << "2. Armas" << endl;
                    cout << "3. Multijugador" << endl;
                    cout << "4. Ropa" << endl;
                    cout << "5. Deportes" << endl;


                    cin >> categoria;
                    while (categoria > 5 || categoria < 1) {
                        cout << "La opcion escogida no es correcta" << endl;
                        cin >> categoria;
                    }
                    switch (categoria)
                    {
                    case 1:
                        categ = eJuegos::autos;
                        break;
                    case 2:
                        categ = eJuegos::armas;
                        break;
                    case 3:
                        categ = eJuegos::multijugador;
                        break;
                    case 4:
                        categ = eJuegos::ropa;
                        break;
                    case 5:
                        categ = eJuegos::deportes;
                        break;

                    }
                    cJuegos* jug = new cJuegos(duracion, nombre, empresa, categ);
                    AgregarServicio(jug);
                }
                break;
            }
            case 2:
            {
                string srv;
                cout << "INGRESE el nombre del servicio que desea QUITAR" << endl;
                getline(cin, srv);
                getline(cin, srv);
                if (EliminarServicio(srv)) {
                    cout << "Se ha quitado el servicio" << endl;

                }
                else {
                    cout << "Ha ocurrido un error" << endl;
                }
                break;
            }
            case 3:
            {
                string srv;
                cout << "INGRESE el nombre del servicio que desea BUSCAR" << endl;
                getline(cin, srv);
                getline(cin, srv);
                cServicio* servicio = BuscarServicio(srv);
                if (servicio) {
                    servicio->Imprimir();
                }
                else {
                    cout << "NO SE HA ENCONTRADO EL SERVICIO"<<endl;
                }
                break;
            }
            case 4:
            {
                string nombre, apellido, pais, password, aux;
                eCliente categoria;
                int op;
                cout << "Desea agregar: " << endl;
                cout << "1.Usuario" << endl;
                cout << "2.Administrador" << endl;
                cin >> op;
                cout << "Ingrese el nombre..." << endl;
                cin >> nombre;
                cout << "Ingrese el apellido..." << endl;
                cin >> apellido;
                cout << "Ingrese el pais..." << endl;
                getline(cin,pais);
                getline(cin, pais);
            CONTRASENIA:
                /*UNA password es strong si contiene:
                    una letra uppercase
                    una letra lowercase
                    un digito
                    un simbolo
                    una longitud mayor a 8*/
                cout << "Ingrese la contrasenia..." << endl;
                cin >> password;
                while (contraseniaSegura(password)) {//mientras la contrasenia no sea los suficientemente segura
                    cout << "Ingrese nuevamente la contrasenia..." << endl;
                    cin >> password;
                }
                cout << "VERIFICAR las contrasenias..." << endl; //checkeo que sea igual a la introducida
                cin >> aux;
                if (aux.compare(password) != 0) {
                    cout << "Las contrasenias NO coinciden" << endl;
                    goto CONTRASENIA;
                }

                if (op == 1) {
                    cout << "Ingrese la categoria del usuario: " << endl;
                    cout << "1.Premium" << endl;
                    cout << "2.Basico" << endl;
                    cout << "3.Gratis" << endl;
                    cin >> op;
                    switch (op)
                    {
                    case 1:
                        categoria = eCliente::premium;
                        break;
                    case 2:
                        categoria = eCliente::basico;
                        break;
                    case 3:
                        categoria = eCliente::gratis;
                        break;
                    default:
                        cout << "La categoria introducida NO es correcta"<<endl;
                        break;
                    }
                    cBaseDatos::AgregarPersonas(new cUsuario(categoria, nombre, apellido, pais, password));
                    cout << "Se ha agregado a " << apellido << " exitosamente" << endl;
                }
                else if (op == 2) {
                    cBaseDatos::AgregarPersonas(new cAdministrador(nombre, apellido, pais, password));
                    cout << "Se ha agregado a " << apellido << " exitosamente" << endl;
                }
                else {
                    cout << "NO ha introducido una opcion correcta" << endl;
                }
                break;
            }
            case 5:
            {
                string srv; int op=0;
                cout << "INGRESE el user-name de la que desea ELIMINAR" << endl;
                getline(cin, srv);
                getline(cin, srv);
                cPersona* persona = cBaseDatos::BuscarPersona(srv);
                if ((adm->getID()).compare(persona->getID()) == 0) { //si me quiero borrar a mi mismo
                    cout << "ESTA SEGURO QUE DESEA ELIMINARSE A USTED MISMO?" << endl;
                    cout << "0. NO " << endl;
                    cout << "1. YES" << endl;
                    cin >> op;
                    if (op) {

                    }else{
                       break; 
                    }
                }
                if (persona) {
                    if (cBaseDatos::EliminarPersonas(persona)) {
                        cout << "Se ha quitado la persona" << endl;
                        if (op) {
                            cont = 0;   //se reinicia el contador de intentos 
                            goto SESION;
                        }
                    }
                    else {
                        cout << "Ha ocurrido un error" << endl;
                    }
                }
                else {
                    cout << "NO SE HA encontrado a la persona" << endl;
                }
                break;
            }
            case 6:
            {
                int k,q;
                cout << "----ESTADISTICAS----"<<endl;
                cout << "1. Mas vistos" << endl;
                cout << "2. Mas jugados" << endl;
                cout << "3. Mas escuchados" << endl;
                cout << "4. Tiempo peliculas" << endl;
                cout << "5. Tiempo audios" << endl;
                cout << "6. Tiempo juegos" << endl;
                cout << "7. Tiempo de un USUARIO en c/categ" << endl;
                cout << "8. Porcentaje de USUARIOS online" << endl;
                cout << "9. Mas escuchados" << endl;

                cin >> k;
                switch (k)
                {
                case 1:
                    cout << "Cantidad a mostrar" << endl;
                    cin >> q;
                    PeliculaMasVista(q);
                    break;
                case 2:
                    cout << "Cantidad a mostrar" << endl;
                    cin >> q;
                    JuegoMasJugado(q);
                    break;
                case 3:
                    cout << "Cantidad a mostrar" << endl;
                    cin >> q;
                    AudioMasEscuchado(q);
                    break;
                case 4:
                    cout<< "Tiempo peliculas: "<<cLogger::CantTiempoPeliculas()<<endl;
                    break;
                case 5:
                    cout<<"Tiempo audios: "<<cLogger::CantTiempoAudios()<<endl;
                    break;
                case 6:
                    cout << "Tiempo juegos: " << cLogger::CantTiempoJuegos()<<endl;
                    break;
                case 7:
                {
                    cout << "Ingrese nombre del usuario" << endl;
                    string usercode;
                    cin >> usercode;
                    int* arr = cLogger::cantTiempoUsuario(usercode);//parametro codigo del user
                    cout << "Peliculas: "<<arr[0] << endl;          //retorna un array con los tiempos
                    cout << "Juegos: " << arr[1] << endl;
                    cout << "Audios: " << arr[2] << endl;
                    break;
                }
                case 8:
                {
                    cout << adm->getOnline() << endl;
                    cout<<"PERSONAS CONECTADAS: "<<cBaseDatos::personasConectadas()<<" %"<<endl;
                    break;
                }
                default:
                    cout << "No se ha ingresado una opcion correcta" << endl;
                    break;
                }
                break;
            }
            case 7:
                cont = 0; //reiniciamos el contador
                goto SESION;

            case 0:
                cout << "ESTA SEGURO QUE QUIERE APAGAR EL DISPOSITIVO?" << endl;
                cout << "0. NO" << endl;
                cout << "1. SI" << endl;
                cin >> confirmation;
                if (confirmation) {
                    //cambiamos el status online a false
                    adm->setOnline();
                    return;
                }
                break;
            default:
                if (x != 0) {
                    cout << "NINGUNA DE LAS OPCIONES esta disponible" << endl;
                    cout << "porfavor pruebe otra vez" << endl;
                }
            }
        }
    }
    else {
        cout << "SU usuario o contraseña es incorrecta"<<endl;
        cout << "Ingrese nuevamente su contraseña"<<endl;
        cont++; //se permitira 5 veces la introducicion de las mismas
        //de modo de evitar una pentracion a nuestro sistema por fuerza bruta
        if (cont<=5){
            goto SESION;
        }
    }
}

void cStreamingService::AudioMasEscuchado(int n) {
    int aux;
    vector<pair<string, int>> repeticiones = cLogger::Masescuchados();
    cout << "LOS " << n << " AUDIOS MAS ESCUCHADOS" << endl;
    n > repeticiones.size() ? aux = repeticiones.size() : aux = n; //ERROR POR INDICE FUERA DEL RANGO
    for (int i = 0;i < aux;i++) {
        cServicio* serv = listaServicios.BuscarItemCodigo<cAudio>(repeticiones[i].first);
        if (serv) {
            cout << i + 1 << ". " << "Titulo: " << serv->getNombre() << " " << "Reproducciones: " << repeticiones[i].second << endl;
        }
        else {
            cout << i + 1 << ". " << "NO FUE ENCONTRADO" << endl;
        }
    }
}

void cStreamingService::PeliculaMasVista(int n) {
    int aux;
    vector<pair<string, int>> repeticiones = cLogger::Masvistos();
    cout << "LAS " << n << " PELICULAS MAS VISTAS" << endl;
    n > repeticiones.size() ? aux = repeticiones.size() : aux = n;
    for (int i = 0;i < aux;i++) {
        cServicio* serv = listaServicios.BuscarItemCodigo<cPeliculas>(repeticiones[i].first);
        if (serv) {
            cout << i + 1 << ". " << "Titulo: " << serv->getNombre() << " " << "Reproducciones: " << repeticiones[i].second << endl;
        }
        else {
            cout << i + 1 << ". " << "NO FUE ENCONTRADA" << endl;
        }
    }
}

void cStreamingService::JuegoMasJugado(int n) {
    int aux;
    vector<pair<string, int>> repeticiones = cLogger::Masjugados();
    cout << "LOS " << n << " JUEGOS MAS JUGADOS" << endl;
    n > repeticiones.size() ? aux = repeticiones.size() : aux = n;
    for (int i = 0;i < aux;i++) {
        cServicio* serv = listaServicios.BuscarItemCodigo<cJuegos>(repeticiones[i].first);
        if (serv) {
            cout << i + 1 << ". " << "Titulo: " << serv->getNombre() << " " << "Reproducciones: " << repeticiones[i].second << endl;
        }
        else {
            cout << i + 1 << ". " << "NO FUE ENCONTRADO" << endl;
        }
    }
}

bool contraseniaSegura(string password)
{
    int l_case = 0, u_case = 0, digit = 0, special = 0;
    int l = password.length(), i;

    for (i = 0;i < l;i++)
    {
        if (islower(password[i]))
            l_case = 1;
        if (isupper(password[i]))
            u_case = 1;
        if (isdigit(password[i]))
            digit = 1;
        if (!isalpha(password[i]) && !isdigit(password[i]))
            special = 1;
    }

    if (l_case && u_case && digit && special && l >= 8) {
        cout << "Strong password." << endl;
        return false;
    }
    else {
        cout << "Weak password" << endl;
        return true;
    }

}