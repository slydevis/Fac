import javax.swing.*;
import javax.swing.plaf.basic.BasicArrowButton;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class Taquin extends JFrame {

    private JButton tabButton[][];
    private int n;

    public Taquin(int n, int value[][])
    {
        super( "Taquin" );
        setDefaultCloseOperation( EXIT_ON_CLOSE );

        this.n = n;
        tabButton = new JButton[n][n];

        JPanel panel = new JPanel(new GridLayout(n, n));
        JButton button = new JButton("Vérifier");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if(checkEnd())
                    JOptionPane.showMessageDialog(null, "C'est fini !" );
                else
                    JOptionPane.showMessageDialog(null, "Fail !" );
            }
        });

        for(int i = 0; i < n; ++i){
            for( int j = 0; j < n; ++j ){
                if(value[i][j] == 0)
                    tabButton[i][j] = new JButton("");
                else
                    tabButton[i][j] = new JButton(String.valueOf(value[i][j]));

                tabButton[i][j].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        searchNearEmptyCase(getPosButton((JButton) actionEvent.getSource()));
                        //searchEmptyCase(searchCase(((JButton) actionEvent.getSource())));
                    }
                });

                panel.add(tabButton[i][j] );
            }
        }

        add(panel, BorderLayout.CENTER);
        add(button, BorderLayout.SOUTH);

        pack();
        setVisible( true );
    }

    private boolean checkEnd(){
        int tmp[] = new int[n*n];
        for(int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j)
                tmp[i*n + j] = Integer.valueOf(tabButton[i][j].getText().equals( "" ) ? "0" : tabButton[i][j].getText());

        for(int i = 1; i < (n*n) -1; ++i)
            if(tmp[i - 1] > tmp[i])
                return false;

        return true;
    }

    private void swapJButton( JButton a, JButton b) {
        String c = a.getText();
        a.setText(b.getText());
        b.setText(c);
    }

    private int[] getPosButton(JButton button)
    {
        int[] pos = new int[2];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(tabButton[i][j] == button) {
                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }

        return pos;
    }

    private void searchNearEmptyCase(int[] pos) {
        if(isEmptyCase(pos[0], pos[1] - 1)) {
            swapJButton(tabButton[pos[0]][pos[1] - 1], tabButton[pos[0]][pos[1]]);
        }
        else if(isEmptyCase(pos[0], pos[1] + 1)){
            swapJButton(tabButton[pos[0]][pos[1] + 1], tabButton[pos[0]][pos[1]]);
        }
        else if(isEmptyCase(pos[0] - 1, pos[1])){
            swapJButton(tabButton[pos[0] - 1][pos[1]], tabButton[pos[0]][pos[1]]);
        }
        else if(isEmptyCase(pos[0] + 1, pos[1])){
            swapJButton(tabButton[pos[0] + 1][pos[1]], tabButton[pos[0]][pos[1]]);
        }
    }

    private boolean isEmptyCase(int x, int y) {
        if((x < 0 || x >= n))
            return false;

        if((y < 0 || y >= n))
            return false;

        JButton button = tabButton[x][y];
        if(button.getText().equals(""))
            return true;

        return false;
    }
}
