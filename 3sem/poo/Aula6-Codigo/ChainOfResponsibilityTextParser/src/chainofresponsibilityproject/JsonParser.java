/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chainofresponsibilityproject;

/**
 *
 * @author http://blog.sanaulla.info/2012/09/23/simple-example-to-illustrate-chain-of-responsibility-design-pattern/
 */
public class JsonParser extends Parser{
 
  public JsonParser(Parser successor){
    this.setSuccessor(successor);
  }
   
  protected boolean canHandleFile(String fileName){
    return fileName.endsWith(".json");
  }  
  
  protected void parseFile(String fileName) {
    System.out.println("A JSON parser is handling the file: "+fileName);
  }
}
