# TreekoEngine
Visión General de la Arquitectura del Motor
Un desglose del pipeline de renderizado de DirectX 11 y el flujo de datos del proyecto.

El Flujo del Pipeline
El flujo se divide en 3 fases principales:

1. Inicialización: Prepara a la GPU y todos los componentes de la API para comenzar a dibujar.

2. Bucle de Renderizado: El ciclo que se ejecuta en cada fotograma para actualizar y dibujar la escena.

3. Limpieza: Libera todos los recursos cuando la aplicación se cierra.

1. Fase de Inicialización
Esta fase configura todos los objetos de la API necesarios antes de que comience el bucle principal.

A. El Entorno (Núcleo de la API)
Window: Encapsula la creación y gestión de la ventana del sistema operativo donde se mostrará la información renderizada.

Device: Actúa como la "fábrica" de recursos de la GPU. Se usa para crear texturas, buffers, shaders, etc.

Device Context: Su responsabilidad es enviar comandos directos a la GPU, como configuraciones del pipeline o comandos de dibujo.

Swap Chain: Gestiona los búferes de imagen y utiliza la función Present() para dibujarlos en la pantalla.

Front Buffer: Almacena la información ya procesada por los shaders, lista para leerse y dibujarse.

Back Buffer: Es el destino de todos los comandos de dibujo del Device Context.

B. Lienzos de Renderizado
Texture: Crea los recursos base que se utilizarán para el Back Buffer y el Depth Buffer.

Render Target View (RTV): Define al Back Buffer como el destino principal para el almacenamiento de los datos de renderizado.

Depth Stencil View (DSV): Configura el Depth Buffer para almacenar los valores de profundidad, esencial para la oclusión 3D.

C. Datos y Programas de la GPU
Compilación de Shaders: Se compilan los programas Vertex Shader y Pixel Shader desde sus respectivos archivos (.fx o .hlsl).

Creación de Buffers: Se crea el VertexBuffer (VBO) y el IndexBuffer (IBO), donde se almacenan los datos de los vértices y los índices que indican cómo conectarlos.

Carga de Recursos Visuales: Se cargan las texturas (ej. .dds, .png) y se crea un Sampler State para definir cómo se filtrarán y leerán en los shaders.

Manejo de Fallos: En caso de no poder inicializar alguno de los componentes, se debe llamar a la función de limpieza para liberar todos los recursos creados hasta el momento y finalizar el programa de forma segura.

2. Bucle de Renderizado
Este es el bucle principal del motor (while (true)), que se ejecuta en cada fotograma.

Actualización de la Escena (CPU): La CPU actualiza los datos que cambian en cada fotograma (ej. matrices de transformación de los objetos). Estos datos se copian a los Constant Buffers por medio del Device Context.

Renderizado (GPU):

Se limpia el Back Buffer (usando el Render Target View) con un color de fondo.

Se limpia el Depth Buffer (usando el Depth Stencil View) para calibrar las pruebas de profundidad.

Ejecución de Comandos de Dibujo:

El Device Context configura el pipeline, asignando los vertex y pixel shaders.

Se enlazan los constant buffers, texturas y samplers a los shaders.

Se llama a la función DrawIndexed() para que la GPU procese y renderice la geometría definida.

Presentación en Pantalla: Se le ordena al Swap Chain intercambiar el Front Buffer y el Back Buffer (usando el método Present()), haciendo visible el nuevo fotograma recién renderizado.

3. Fase de Limpieza
Cuando la aplicación se cierra (o falla), se llama a la función CleanupDevice() para liberar todos los recursos de la GPU (texturas, shaders, buffers, vistas, etc.) en orden inverso a su creación para evitar fugas de memoria.

Componente Clave: ModelLoader (Parser .obj)
ModelLoader (ModelLoader.h) es una clase de utilidad esencial diseñada para analizar (parsear) archivos de geometría en formato .obj.

Su única responsabilidad es leer el archivo .obj, procesar los datos de vértices y llenar un MeshComponent con la geometría lista para usarse en la CPU.

Importante: Esta clase está desacoplada de DirectX. No crea ningún recurso de GPU (como ID3D11Buffer). Su trabajo es preparar el MeshComponent, que luego es utilizado por la clase Buffer para crear los VertexBuffer e IndexBuffer correspondientes.

Formato .obj
Un archivo .obj separa sus datos según prefijos. El ModelLoader procesa los siguientes:

v: Define las posiciones (X, Y, Z) del vértice en el espacio.

vt: Define las coordenadas de textura (U, V).

vn: Define las normales del vértice (X, Y, Z).

f: Define una cara. Instruye cómo ensamblar los vértices, indicando el índice de la posición, la textura y la normal (v/vt/vn).

Ejemplo: f 1/7/5 2/8/5 3/9/5

El ModelLoader puede manejar caras de 3 bloques (triángulos) y de 4 bloques (Quads), aplicando una "Triangulación en Abanico" (Fan Triangulation) a estos últimos.