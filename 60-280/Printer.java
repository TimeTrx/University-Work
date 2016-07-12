// Lab 4 Solution: Printer.java
// This program creates a simple Printer GUI

import javax.swing.JFrame;

public class Printer
{
   public static void main( String[] args )
   {
      PrinterFrame printerFrame = new PrinterFrame();
      printerFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      printerFrame.setSize( 400, 200 ); // set frame size
      printerFrame.setVisible( true ); // display frame
   } // end main
} // end class Printer

