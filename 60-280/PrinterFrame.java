// Lab 4 Tem[late: PrinterFrame.java
// This program creates a simple Printer GUI

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JToggleButton;
import javax.swing.JCheckBox;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.JComboBox;
import javax.swing.JPanel;

public class PrinterFrame extends JFrame
{
   private JButton button1;
   private JButton button2;
   private JButton button3;
   private JButton button4;
   private JToggleButton toggle1;
   private JCheckBox check1;
   private JCheckBox check2;
   private JCheckBox check3;
   private JRadioButton radio1;
   private JRadioButton radio2;
   private JRadioButton radio3;
   private ButtonGroup radioGroup;
   private JComboBox comboBox;
   private JLabel label1;
   private JLabel label2;
   private JPanel panel1;
   private JPanel panel2;
   private JPanel panel3;
   private JPanel panel4;
   private JPanel panel5;
   private JPanel panel6;
   private JPanel panel7;

   private String[] quality = {"High", "Medium", "Low"};

   // constructor sets up GUI
   public PrinterFrame()
   {
      super( "Printer" );

      // build left north panel
      label1 = new JLabel( "Printer: MyPrinter" );
      panel1 = new JPanel();
      panel1.setLayout( new FlowLayout( FlowLayout.LEFT ) );
      panel1.add( label1 );

      // build right east panel
      /******
         Create the buttons "OK", "Cancel", "Setup..."
         and "Help". Built a panel (panel2), set proper
         layout and add the buttons to the panel

      ******/
      button1 = new JButton("OK");
      button2 = new JButton("Cancel");
      button3 = new JButton("Setup...");
      button4 = new JButton("Help");
      panel2 = new JPanel();
      panel2.setLayout(new GridLayout(4,1,5,5));
      panel2.add(button1);
      panel2.add(button2);
      panel2.add(button3);
      panel2.add(button4);
      // build left south panel
      /******
	     Create the combo box (with "quality"), the
	     toggle button and the corresponding labels.
	     Built a panel (panel3) with proper layout
	     and add the components created
      ******/
      comboBox = new JComboBox(quality);
      toggle1= new JToggleButton("Print to File");
      label2 = new JLabel("Print Quality");
      panel3 = new JPanel();
      panel3.setLayout(new FlowLayout(FlowLayout.CENTER, 10 ,10));
      panel3.add(label2);
      panel3.add(comboBox);
      panel3.add(toggle1);
      // build left east panel
      /******
	  	 Create check boxes for "Image", "Text" and "Code",
	  	 built a panel (panel4), set proper layout and
	  	 add the check boxes
      ******/
      check1 = new JCheckBox("Image");
      check2 = new JCheckBox("Text");
      check3 = new JCheckBox("Code");
      panel4 = new JPanel();
      panel4.setLayout(new GridLayout(3, 1));
      panel4.add(check1);
      panel4.add(check2);
      panel4.add(check3);
      // build left west panel
      /******
	  	 Create the radio buttons for "Selection", "All" and "Applet",
	  	 built a panel (panel5), set proper layout and
	  	 add the radio buttons

      ******/
      radio1 = new JRadioButton("Selection");
      radio2 = new JRadioButton("All");
      radio3 = new JRadioButton("Applet");
      panel5 = new JPanel();
      panel5.setLayout(new GridLayout(3,1));
      panel5.add(radio1);
      panel5.add(radio2);
      panel5.add(radio3);
      // group the radio buttons
	  /*******
	     Create a radio group and the radio buttons to it
	  *******/
      radioGroup = new ButtonGroup();
      radioGroup.add(radio1);
      radioGroup.add(radio2);
      radioGroup.add(radio3);
      // build left center
      /******
	  	 Built a panel (panel6) with the background
	  	 color as light gray, set its layout and
	  	 add panel4 and panel5 to it
      ******/
      panel6 = new JPanel();
      panel6.setBackground(Color.lightGray);
      panel6.setLayout(new FlowLayout(FlowLayout.CENTER));
      panel6.add(panel4);
      panel6.add(panel5);
      // set up left panel
      /******
	  	 Built a panel (panel7), set its layout
	  	 and add panel1, panel6 and panel3 to it
      ******/
      panel7 = new JPanel();
      panel7.setLayout(new GridLayout(3,1));
      panel7.add(panel1);
      panel7.add(panel6);
      panel7.add(panel3);
      // set up frame layout
      setLayout( new FlowLayout());
	  add( panel7 );
      add( panel2 );
   } // end PrinterFrame constructor
} // end class PrinterFrame

