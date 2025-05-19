import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class VentanaPrincipal extends JFrame {
    private JPanel mainPanel;
    private JTextArea listaPersonajesTextArea;
    private JTextField idTextField;
    private JTextField nombreTextField;
    private JComboBox claseComboBox;
    private JTextField fuerzaTextField;
    private JComboBox rarezaComboBox;
    private JButton agregarButton;
    private JTextField buscarNombreTextField;
    private JButton buscarButton;
    private JTextArea resultadosBusquedaTextArea;
    private JButton ordenarButton;

    private SistemaGestionPersonajes sistema = new SistemaGestionPersonajes();

    public VentanaPrincipal() {
        setTitle("Sistema de Gestión de Personajes");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(mainPanel);
        setSize(600, 400); // Ajusta el tamaño según necesites
        setLocationRelativeTo(null);

        // Inicializar ComboBoxes
        claseComboBox.addItem("Guerrero");
        claseComboBox.addItem("Arquero");
        claseComboBox.addItem("Mago");
        rarezaComboBox.addItem("Común");
        rarezaComboBox.addItem("Raro");
        rarezaComboBox.addItem("Épico");
        rarezaComboBox.addItem("Legendario");

        // Mostrar datos iniciales
        mostrarPersonajes();

        // Configurar Listeners
        agregarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                agregarNuevoPersonaje();
            }
        });

        buscarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                buscarPersonajesPorNombre();
            }
        });

        ordenarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ordenarYMostrarPorFuerza();
            }
        });
    }

    private void mostrarPersonajes() {
        listaPersonajesTextArea.setText("");
        ArrayList<Personaje> personajes = sistema.getPersonajes();
        for (Personaje personaje : personajes) {
            listaPersonajesTextArea.append(personaje.toString() + "\n");
        }
    }

    private void agregarNuevoPersonaje() {
        try {
            int id = Integer.parseInt(idTextField.getText());
            String nombre = nombreTextField.getText();
            String clase = (String) claseComboBox.getSelectedItem();
            int fuerza = Integer.parseInt(fuerzaTextField.getText());
            String rareza = (String) rarezaComboBox.getSelectedItem();

            if (sistema.agregarPersonaje(id, nombre, clase, fuerza, rareza)) {
                mostrarPersonajes(); // Actualizar la lista
                limpiarCampos();
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Por favor, ingrese datos válidos para ID y Fuerza.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void buscarPersonajesPorNombre() {
        String nombreBuscar = buscarNombreTextField.getText();
        ArrayList<Personaje> resultados = sistema.buscarPersonajesPorNombre(nombreBuscar);
        resultadosBusquedaTextArea.setText(""); // Limpiar el área de resultados
        if (resultados.isEmpty()) {
            resultadosBusquedaTextArea.append("No se encontraron personajes con el nombre: " + nombreBuscar);
        } else {
            for (Personaje personaje : resultados) {
                resultadosBusquedaTextArea.append(personaje.toString() + "\n");
            }
        }
    }

    private void ordenarYMostrarPorFuerza() {
        sistema.ordenarPorFuerzaDescendente();
        mostrarPersonajes();
    }

    private void limpiarCampos() {
        idTextField.setText("");
        nombreTextField.setText("");
        fuerzaTextField.setText("");
        buscarNombreTextField.setText("");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new VentanaPrincipal().setVisible(true);
            }
        });
    }
}
