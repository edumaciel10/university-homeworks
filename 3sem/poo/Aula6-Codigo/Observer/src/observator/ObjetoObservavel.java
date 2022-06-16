package observator;

import java.util.Observable;

/**
 *
 * @author junio
 */
public class ObjetoObservavel extends Observable{
    private int x;
    private int y;

    public ObjetoObservavel() {
        this.x = 1;
        this.y = 1;
    }

    public void setX(int x) {
        this.x = x;
        this.setChanged();
    }

    public void setY(int y) {
        this.y = y;
        this.setChanged();
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
