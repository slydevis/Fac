import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainTaquin extends JFrame {
    public MainTaquin()
    {
        super("Taquin");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        TextField textField = new TextField(2);
        textField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                MainTaquin.this.dispose();
                int n = Integer.valueOf(actionEvent.getActionCommand());
                new TaquinBuild(n);
            }
        });

        add(new Label("Taille du Taquin ? "));
        add(textField);

        pack();
        setVisible( true );
    }

    public static void main(String argv[]) {
        new MainTaquin();
    }
}


