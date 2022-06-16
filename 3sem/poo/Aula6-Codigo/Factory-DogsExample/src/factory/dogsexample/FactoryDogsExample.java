/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factory.dogsexample;

/**
 *
 * @author http://alvinalexander.com/java/java-factory-pattern-example
 */
public class FactoryDogsExample {

    /**
     * @param args the command line arguments
     */
public static void main(String[] args)
  {
    // create a small dog
    Dog dog = DogFactory.getDog("small");
    dog.speak();

    // create a big dog
    dog = DogFactory.getDog("big");
    dog.speak();

    // create a working dog
    dog = DogFactory.getDog("medium");
    dog.speak();
  }
}
