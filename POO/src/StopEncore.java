import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StopEncore extends JFrame {
    private JButton stop;
    private JButton encore;
    private JPanel container = new JPanel();

    public StopEncore()
    {
        this.setTitle("Stop Encore");
        stop = new JButton("Stop");
        encore = new JButton("Encore");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        stop.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                StopEncore.this.dispose();

            }
        });

        encore.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new StopEncore();

            }
        });
        container.add(encore);
        container.add(stop);
        this.setContentPane(container);
        this.setVisible(true);
        this.pack();
    }
    public static void main(String[] args) {
        StopEncore stopEncore = new StopEncore();
    }
}
