import java.applet.AudioClip;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;
import javax.swing.*;



public class gui extends JFrame implements ActionListener {
	File soundfile;
	Clip clip;
	JTextField text1;
	JTextField text2;
	Boolean music = false;
	AudioInputStream audioin;
	public gui() throws IOException{
		super("Image Viewer");
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//GridLayout NewLayout = new GridLayout(1,7);
		JLabel label1 = new JLabel("Set Scale");
		 text1 = new JTextField(10);
		soundfile = new File("C:\\Users\\LenovoT540p\\Downloads\\bass.wav");
		try{
			AudioInputStream audioin = AudioSystem.getAudioInputStream(soundfile);
			clip = AudioSystem.getClip();
			clip.open(audioin);
		}
	catch (UnsupportedAudioFileException e) {
        e.printStackTrace();
     } catch (IOException e) {
        e.printStackTrace();
     } catch (LineUnavailableException e) {
        e.printStackTrace();
     }
		text1.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				String thetext = e.getActionCommand();
				try{
					int a = Integer.parseInt(thetext);
				}catch(Exception p){
					
				}
			}
			
		});
		text1.setText("100");
		JLabel label2 = new JLabel("Set Speed");
		 text2 = new JTextField(10);
		text2.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				String thetext = e.getActionCommand();
				try{
					int a = Integer.parseInt(thetext);
				}catch(Exception p){
					
				}
			}
			
		});
		text2.setText("50");
		JButton button1 = new JButton("Start Animation");
		button1.addActionListener(this);
		JButton button2 = new JButton("Stop Animation");
		button2.addActionListener(this);
		JCheckBox checkbox1 = new JCheckBox("Play Music");
		checkbox1.addActionListener(this);
		setLayout(new FlowLayout());
		add(label1);
		add(text1);
		add(label2);
		add(text2);
		add(button1);
		add(button2);
		add(checkbox1);
		
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		String buttonstring = e.getActionCommand();
		
		if(buttonstring.equals("Start Animation"))
		{
			System.out.println("Start");
		}
		if(buttonstring.equals("Stop Animation"))
		{
			System.out.println("Stop");
		}
		if(buttonstring.equals("Play Music"))
		{
			if(music == true)
			{
				
				clip.stop();
				
				music = false;
			}
			else
			{
				//clip.start();
				clip.loop(1000);
				//System.out.println("test");
				music = true;
			}
		}
		
		
	}
	
	
}
