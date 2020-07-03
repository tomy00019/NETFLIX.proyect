#include "cStreamingService.h"
#include "cBaseDatos.h"

long long getTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);  //se debe calibrar-->experimenta un desfazaje
    long long date = (1900 + ltm->tm_year) * 10000 + (1 + ltm->tm_mon) * 100 + (ltm->tm_mday);
    long long time = (ltm->tm_hour) * 10000 + (ltm->tm_min) * 100 + (1 + ltm->tm_sec);
    return date * 1000000 + time;
}

pair<long long, string> cStreamingService::SELECCION() {//retorna el timestamp(timepo pasado en el servicio
    cout << "QUE DESEA VER?..." << endl;
    cout << "Por favor INGRESE el nombre de la PELICULA" << endl;
    string nombre;  
    cin >> nombre;
    //el servicio mencionado existe?
    cPeliculas* pel = dynamic_cast<cPeliculas*>(BuscarServicio(nombre));
    cJuegos* jug = dynamic_cast<cJuegos*>(BuscarServicio(nombre));
    cAudio* aud = dynamic_cast<cAudio*>(BuscarServicio(nombre));
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
        pel->Imprimir();
        cout << "OPCIONES" << endl;
        cout << "1. Descargar" << endl;
        cout << "2. Iniciar" << endl;
        cout << "3. Pausar" << endl;
        cout << "4. Retroceder" << endl;
        cout << "5. Adelantar" << endl;
        cout << "6. Grabar" << endl;
        cout << "7. Apagar" << endl;
        int option; 
        cin >> option;
        switch (option) { //problemas con user-interaction
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
    else if (jug) {
        jug->Imprimir();
        cout << "OPCIONES" << endl;
        cout << "1. Descargar" << endl;
        cout << "2. Iniciar" << endl;
        cout << "3. Pausar" << endl;
        cout << "4. Guardar" << endl;
        cout << "5. Comandos" << endl;
        cout << "6. Apagar" << endl;
        int option;
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
            return make_pair((getTime() - inicio), pel->getCodigo());

        default:
            cout << "NO SE HA INTRODUCIDO UNA OPCION CORRECTA";
        }
    }
    else if (aud) {
        aud->Imprimir();
        cout << "OPCIONES" << endl;
        cout << "1. Descargar" << endl;
        cout << "2. Iniciar" << endl;
        cout << "3. Pausar" << endl;
        cout << "4. Retroceder" << endl;
        cout << "5. Adelantar" << endl;
        cout << "6. Grabar" << endl;
        cout << "7. Apagar" << endl;
        int option;
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
            return make_pair((getTime() - inicio), pel->getCodigo());

        default:
            cout << "NO SE HA INTRODUCIDO UNA OPCION CORRECTA";
        }
    }
    return make_pair(0, "");
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
	int x,w,p, cont=0;
    //se abre la app
    //se guarda el tiempo de inicio de la sesion
    //al cerrar sesion creo un log
SESION:
    cPersona* per = inicioSesion();
    cUsuario* user = dynamic_cast<cUsuario*>(per);
    cAdministrador* adm = dynamic_cast<cAdministrador*>(per);
    if (user) {//se dividen las opciones para los usuarios y los administradores
        cout << "SEA BIENVENIDO USUARIO" << endl;
        cout << "MENU" << endl;
        cout << "1. PELICULAS" << endl;
        cout << "2. JUEGOS" << endl;
        cout << "3. AUDIOS" << endl;
        cout << "4. TODOS" << endl;
        cout << "0. APAGAR" << endl;
        cin >> x;
        switch (x) {
        case 1:
            ListarCategoria<cPeliculas>();
            cout << "CATEGORIAS:" << endl;
            cout << "1. ACCION" << endl;
            cout << "2. AVENTURA" << endl;
            cout << "3. COMEDIA" << endl;
            cout << "4. TERROR" << endl;
            cout << "5. MISTERIO" << endl;
            cout << "6. DOCUMENTAL:" << endl;
            cout << "7. AMOR" << endl;
            cout << "8. TODOS" << endl;
            cin >> w;
            switch (w) {
            case 1:
            {
                ListarCategoria<cPeliculas>(ePeliculas::accion);
                pair<long long, string> info = SELECCION();
                long long timestamp = info.first;
                string codigo = info.second;
                int idUsuario = user->getID();
                cLog* log = new cLog(idUsuario, codigo, timestamp);
                cLogger::Registrar(log);
                break;
            }
            case 2:
                ListarCategoria<cPeliculas>(ePeliculas::aventura);
                SELECCION();
                break;
            case 3:
                ListarCategoria<cPeliculas>(ePeliculas::comedia);
                SELECCION();
                break;
            case 4:
                ListarCategoria<cPeliculas>(ePeliculas::terror);
                SELECCION();
                break;
            case 5:
                ListarCategoria<cPeliculas>(ePeliculas::misterio);
                SELECCION();
                break;
            case 6:
                ListarCategoria<cPeliculas>(ePeliculas::documental);
                SELECCION();
                break;
            case 7:
                ListarCategoria<cPeliculas>(ePeliculas::amor);
                SELECCION();
                break;
            case 8:
                ListarCategoria<cPeliculas>();
                SELECCION();
                break;
            default:
                cout << "HA OCURRIDO UN ERROR, porfavor ingrese de nuevo" << endl;
            }
            break;
        case 2:
            ListarCategoria<cJuegos>();
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
                SELECCION();
                break;
            case 2:
                ListarCategoria<cJuegos>(eJuegos::armas);
                SELECCION();
                break;
            case 3:
                ListarCategoria<cJuegos>(eJuegos::multijugador);
                SELECCION();
                break;
            case 4:
                ListarCategoria<cJuegos>(eJuegos::ropa);
                SELECCION();
                break;
            case 5:
                ListarCategoria<cJuegos>(eJuegos::deportes);
                SELECCION();
                break;
            case 6:
                ListarCategoria<cJuegos>();
                SELECCION();
                break;
            default:
                cout << "HA OCURRIDO UN ERROR, porfavor ingrese de nuevo" << endl;
            }
            break;
        case 3:
            ListarCategoria<cAudio>();
            cout << "CATEGORIAS:" << endl;
            cout << "1. PODCAST" << endl;
            cout << "2. CANCION" << endl;
            cout << "3. AUDIOLIBRO" << endl;
            cout << "4. TODOS" << endl;
            cin >> w;
            switch (w) {
            case 1:
                ListarCategoria<cAudio>(eAudio::podcast);
                SELECCION();
                break;
            case 2:
                ListarCategoria<cAudio>(eAudio::cancion);
                SELECCION();
                break;
            case 3:
                ListarCategoria<cAudio>(eAudio::audioLibro);
                SELECCION();
                break;
            case 4:
                ListarCategoria<cAudio>();
                SELECCION();
                break;
            default:
                cout << "HA OCURRIDO UN ERROR, porfavor ingrese de nuevo" << endl;
            }
            break;
        case 4:
            ListarServicios();
            SELECCION();
            break;
        case 0:
            return;
        default:
            cout << "NINGUNA DE LAS OPCIONES esta disponible" << endl;
            cout << "porfavor pruebe otra vez"<<endl;
            break;
        }
    }
    else if (adm) {
        cout << "SEA BIENVENIDO Sr. ADMINISTRADOR" << endl;
        cout << "MENU" << endl;
        cout << "1. AGREGAR SERVICIO" << endl;
        cout << "2. QUITAR SERVICIO" << endl;
        cout << "3. BUSCAR SERVICIO" << endl;
        cout << "4. ELIMINAR USUARIO" << endl;
        cout << "0. APAGAR" << endl;
        cin >> x;
        switch (x) {
        case 1:
        {
            int l;
            cout << "INGRESE el tipo de servicio"<<endl;
            cout << "1.pelicula" << endl;
            cout << "2.audio" << endl;
            cout << "3.juego" << endl;
            cin >> l;
            if (l == 1) {
                int duracion, categoria;
                string nombre;
                ePeliculas categ;
                cout << "Ingrese la duracion de la pelicula" << endl;
                cin >> duracion;
                cout << "Ingrese la el nombre de la pelicula" << endl;
                cin >> nombre;
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

                cPeliculas* pel = new cPeliculas(duracion, nombre, categ);
                AgregarServicio(pel);
            }
            else if (l == 2) {
                int duracion, categoria;
                string nombre;
                eAudio categ;
                cout << "Ingrese la duracion del Audio" << endl;
                cin >> duracion;
                cout << "Ingrese la el nombre del Audio" << endl;
                cin >> nombre;
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
                cAudio* aud = new cAudio(duracion, nombre, categ);
                AgregarServicio(aud);
            }
            else if (l == 3) {
                int duracion, categoria;
                string nombre;
                eJuegos categ;
                cout << "Ingrese la duracion del Juego" << endl;
                cin >> duracion;
                cout << "Ingrese el nombre deL Juego " << endl;
                cin >> nombre;
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
                cJuegos* jug = new cJuegos(duracion, nombre, categ);
                AgregarServicio(jug);
            }


            break;
        }
        case 2:
        {
            string srv;
            cout << "INGRESE el nombre del servicio que desea QUITAR" << endl;
            cin >> srv;
            cServicio* servicio = BuscarServicio(srv);
            QuitarServicio(servicio);
            break;
        }
        case 3:
        {
            string srv;
            cout << "INGRESE el nombre del servicio que desea BUSCAR" << endl;
            cin >> srv;
            cServicio* servicio = BuscarServicio(srv);
            servicio->Imprimir();
            break;
        }
        case 4:
            
            break;
        case 0:
            return;
        default:
            cout << "NINGUNA DE LAS OPCIONES esta disponible" << endl;
            cout << "porfavor pruebe otra vez" << endl;
            break;
        }
    }
    else {
        cout << "SU usuario o contraseña es incorrecta";
        cout << "Ingrese nuevamente su contraseña";
        cont++; //se permitira 5 veces la introducicion de las mismas
        //de modo de evitar una pentracion a nuestro sistema por fuerza bruta
        if (cont<=5){
            goto SESION;
        }
    }
}
