import javafx.geometry.VerticalDirection;

import javax.swing.*;
import java.awt.*;
import java.awt.datatransfer.StringSelection;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MagicSquare extends JFrame {
    private JTextField tabField[][];
    private JLabel horizontalValue[];
    private JLabel verticalValue[];
    private JLabel diagonaleInverse;
    private int n;
    public MagicSquare(int n) {
        super("Magic Square");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        this.tabField = new JTextField[n][n];
        this.verticalValue = new JLabel[n];
        this.horizontalValue = new JLabel[n + 1];
        this.diagonaleInverse = new JLabel("0");
        this.n = n;

        JPanel panel = new JPanel(new GridLayout(n + 2, n + 1));

        for( int i = 0; i < n; ++i ) {
            for (int j = 0; j < n; ++j) {
                tabField[i][j] = new JTextField("0");
                tabField[i][j].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        updateAll();
                    }
                });
                panel.add(tabField[i][j]);
            }
            verticalValue[i] = new JLabel("0");
            panel.add(verticalValue[i]);
        }

        for(int i = 0; i < n + 1; ++i) {
            horizontalValue[i] = new JLabel("0");
            panel.add(horizontalValue[i]);
        }

        diagonaleInverse = new JLabel("9000");
        panel.add(diagonaleInverse);

        add(panel, BorderLayout.CENTER);

        pack();
        setVisible( true );
    }

    public void updateAll()
    {
        // Vertical update

        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = 0; j < n; ++j) {
                if(tabField[i][j].getText() != "")
                    sum += Integer.parseInt(tabField[i][j].getText());

                this.verticalValue[i].setText(String.valueOf(sum));
            }
        }

        // Horizontal update

        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (tabField[j][i].getText() != "")
                    sum += Integer.parseInt(tabField[j][i].getText());

                this.horizontalValue[i].setText(String.valueOf(sum));
            }
        }

        // Diagonale descendante

        int sum = 0;
        int i = 0;
        for(int j = 0; j < n && i < n; ++i, ++j)
        {
            if(tabField[i][j].getText() != "")
                sum += Integer.parseInt(tabField[j][i].getText());
        }


        horizontalValue[n].setText(String.valueOf(sum));

        // Diagonale montante

        sum = 0;
        i = 0;
        for(int j = n - 1; j >= 0 && i < n; ++i, --j)
        {
            if(tabField[i][j].getText() != "")
                sum += Integer.parseInt(tabField[i][j].getText());
        }

        System.out.println(sum);
        diagonaleInverse.setText(String.valueOf(sum));
    }

    public static void main(String argv[]) {
        new MagicSquare(5);
    }
}
