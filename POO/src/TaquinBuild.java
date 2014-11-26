import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TaquinBuild extends JFrame {

    private JTextField tabTextFields[][];
    private int n;

    public TaquinBuild(int n){
        super("Construction du Taquin");
        setDefaultCloseOperation( EXIT_ON_CLOSE );

        this.n = n;
        this.tabTextFields = new JTextField[n][n];

        JPanel panel = new JPanel(new GridLayout(n, n));
        JButton okButton = new JButton("Ok");
        okButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if(TaquinBuild.this.checkGrid()) {
                    TaquinBuild.this.dispose();
                    new Taquin(TaquinBuild.this.n, getIntValue());
                }
                else {
                    JOptionPane.showMessageDialog(null, "Case vide trouvée");
                }
            }
        });

        for( int i = 0; i < n; ++i ) {
            for (int j = 0; j < n; ++j) {
                tabTextFields[i][j] = new JTextField();
                panel.add(tabTextFields[i][j]);
            }
        }

        add(panel, BorderLayout.CENTER);
        add(okButton, BorderLayout.SOUTH);

        pack();
        setVisible(true);
    }

    private boolean checkGrid() {
        boolean emptyCaseFound = false;
        for( int i = 0; i < n; ++i ) {
            for (int j = 0; j < n; ++j) {
                if (tabTextFields[i][j].getText().trim().equals("")) {
                    if (!emptyCaseFound)
                        emptyCaseFound = true;
                    else
                        return false;
                }
            }
        }
        return emptyCaseFound;
    }

    private int[][] getIntValue() {
        int tabIntValue[][] = new int[n][n];

        for( int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!tabTextFields[i][j].getText().trim().equals(""))
                    tabIntValue[i][j] = Integer.valueOf(tabTextFields[i][j].getText());
            }
        }

        return tabIntValue;
    }
}
