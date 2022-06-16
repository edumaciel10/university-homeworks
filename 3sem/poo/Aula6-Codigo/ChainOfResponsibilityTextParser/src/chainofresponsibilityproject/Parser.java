/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chainofresponsibilityproject;

/**
 *
 * @author
 * http://blog.sanaulla.info/2012/09/23/simple-example-to-illustrate-chain-of-responsibility-design-pattern/
 */
public abstract class Parser {

    private Parser successor;

    public Parser getSuccessor() {
        return successor;
    }

    public void setSuccessor(Parser successor) {
        this.successor = successor;
    }

    protected abstract boolean canHandleFile(String fileName);    
    protected abstract void parseFile(String sFileName);
    
    public void parse(String fileName) {
        if (this.canHandleFile(fileName)) {
            this.parseFile(fileName);
        }else if (getSuccessor() != null) {
            getSuccessor().parse(fileName);
        } else {
            System.out.println("Unable to find the correct parser for the file: " + fileName);
        }
    }
}