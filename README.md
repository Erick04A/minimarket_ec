public class Personaje {
    private int id;
    private String nombre;
    private String clase;
    private int fuerza;
    private String rareza;

    public Personaje(int id, String nombre, String clase, int fuerza, String rareza) {
        this.id = id;
        this.nombre = nombre;
        this.clase = clase;
        this.fuerza = fuerza;
        this.rareza = rareza;
    }

    // Getters y Setters
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }
    public String getNombre() { return nombre; }
    public void setNombre(String nombre) { this.nombre = nombre; }
    public String getClase() { return clase; }
    public void setClase(String clase) { this.clase = clase; }
    public int getFuerza() { return fuerza; }
    public void setFuerza(int fuerza) { this.fuerza = fuerza; }
    public String getRareza() { return rareza; }
    public void setRareza(String rareza) { this.rareza = rareza; }

    @Override
    public String toString() {
        return "ID: " + id + ", Nombre: \"" + nombre + "\", Clase: \"" + clase + "\", Fuerza: " + fuerza + ", Rareza: \"" + rareza + "\"";
    }
}
