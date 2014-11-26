import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

@SuppressWarnings("all")
public class FenetreLectureEntier extends JFrame{
    private int nbChoise = 0;
    private JLabel label = new JLabel("Une ComboBox");
    private JPanel container = new JPanel();
    private JTextField jtf = new JTextField("0");
    public boolean isActive = false;
    public FenetreLectureEntier()
    {
        this.setTitle("Animation");
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        container.setBackground(Color.white);
        container.setLayout(new BorderLayout());
        JPanel top = new JPanel();
        jtf.addKeyListener(new ClavierListener());
        jtf.setPreferredSize(new Dimension(150, 30));
        jtf.setForeground(Color.BLUE);
        top.add(label);
        top.add(jtf);
        container.add(top, BorderLayout.NORTH);
        isActive = true;
        this.setContentPane(container);
        this.setVisible(true);
        this.pack();
    }

    public void openPopup()
    {
        isActive = false;
        this.setVisible(false);
        this.dispose();
        JOptionPane.showMessageDialog(this,"Bravo tu as choisi : " + nbChoise);
    }

    public int getNb()
    {
        return this.nbChoise;
    }

    class ClavierListener implements KeyListener{
        public void keyPressed(KeyEvent event) {
            if(event.getKeyCode() == 10)
            {
                nbChoise = Integer.parseInt(jtf.getText());
                openPopup();
            }
        }

        @Override
        public void keyReleased(KeyEvent arg0) {
            // TODO Auto-generated method stub

        }

        @Override
        public void keyTyped(KeyEvent arg0) {
            // TODO Auto-generated method stub

        }
    }

    public static void main(String[] args) {
        FenetreLectureEntier fenetreLectureEntier = new FenetreLectureEntier();
    }
}
