<?xml version="1.0" encoding="UTF-8"?>
<form xmlns="http://www.intellij.com/uidesigner/form/" version="1" bind-to-class="VentanaCine">
  <grid id="27dc6" binding="principal" layout-manager="BorderLayout" hgap="0" vgap="0">
    <constraints>
      <xy x="20" y="20" width="500" height="600"/>
    </constraints>
    <properties>
      <background color="-723724"/>
      <foreground color="-1"/>
    </properties>

    <!-- Panel superior con controles -->
    <grid id="e2a93" layout-manager="GridLayoutManager" row-count="4" column-count="2" hgap="5" vgap="5">
      <constraints border-constraint="North"/>
      <properties>
        <background color="-723724"/>
      </properties>

      <!-- Fila 1: Nombre -->
      <component id="6d9b7" class="javax.swing.JLabel" binding="lblNombre">
        <constraints>
          <grid row="0" column="0" row-weight="0.0" column-weight="0.0"/>
        </constraints>
        <properties>
          <text value="Nombre:"/>
          <foreground color="-1"/>
        </properties>
      </component>
      <component id="4a434" class="javax.swing.JTextField" binding="txtNombre">
        <constraints>
          <grid row="0" column="1" row-weight="0.0" column-weight="1.0" fill="1" anchor="8"/>
        </constraints>
      </component>

      <!-- Fila 2: Película -->
      <component id="f5e8f" class="javax.swing.JLabel" binding="lblPelicula">
        <constraints>
          <grid row="1" column="0" row-weight="0.0" column-weight="0.0"/>
        </constraints>
        <properties>
          <text value="Película:"/>
          <foreground color="-1"/>
        </properties>
      </component>
      <component id="a5a5a" class="javax.swing.JComboBox" binding="comboPeliculas" default-binding="true">
        <constraints>
          <grid row="1" column="1" row-weight="0.0" column-weight="1.0" fill="1"/>
        </constraints>
      </component>

      <!-- Fila 3: Entradas -->
      <component id="3b3b3" class="javax.swing.JLabel" binding="lblEntradas">
        <constraints>
          <grid row="2" column="0" row-weight="0.0" column-weight="0.0"/>
        </constraints>
        <properties>
          <text value="Entradas:"/>
          <foreground color="-1"/>
        </properties>
      </component>
      <component id="c4c4c" class="javax.swing.JSpinner" binding="spinnerEntradas">
        <constraints>
          <grid row="2" column="1" row-weight="0.0" column-weight="1.0" fill="1"/>
        </constraints>
      </component>

      <!-- Fila 4: Estrategia -->
      <component id="d5d5d" class="javax.swing.JRadioButton" binding="rbFIFO">
        <constraints>
          <grid row="3" column="0" row-weight="0.0" column-weight="1.0"/>
        </constraints>
        <properties>
          <text value="FIFO"/>
          <selected value="true"/>
        </properties>
      </component>
      <component id="e6e6e" class="javax.swing.JRadioButton" binding="rbLIFO">
        <constraints>
          <grid row="3" column="1" row-weight="0.0" column-weight="1.0"/>
        </constraints>
        <properties>
          <text value="LIFO"/>
        </properties>
      </component>
    </grid>

    <!-- Área central de información -->
    <scrollpane id="scroll" binding="scrollInformacion">
      <constraints border-constraint="Center"/>
      <component id="txt" class="javax.swing.JTextArea" binding="txtInformacion">
        <properties>
          <editable value="false"/>
          <lineWrap value="true"/>
          <wrapStyleWord value="true"/>
          <background color="-14474752"/>
          <foreground color="-1"/>
          <text value=""/>
        </properties>
      </component>
    </scrollpane>

    <!-- Botón inferior -->
    <component id="btn" class="javax.swing.JButton" binding="btnComprar">
      <constraints border-constraint="South"/>
      <properties>
        <text value="Comprar entradas"/>
      </properties>
    </component>
  </grid>
</form>
