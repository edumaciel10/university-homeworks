import static org.junit.Assert.*;

import org.junit.Test;

public class IdentifierTestCase {

	@Test
	public void lengthGreaterThanZero() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("azz");
		assertEquals(true, output);
	}
	
	
	@Test
	public void lengthEqualZero() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("");
		assertEquals(false, output);
	}

	@Test
	public void validIdAndLengthLowerThan6AndGreaterThan1() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("aaaaa");
		assertEquals(true, output);
	}

	@Test
	public void validIdAndLengthGreaterThan6() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("aaaaaaa");
		assertEquals(false, output);
	}
	
	@Test
	public void lengthEqualOne() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("a");
		assertEquals(true, output);
	}
	@Test
	public void lengthGreaterThanOneAndInvalidChar() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("§§§");
		assertEquals(false, output);
	}

	@Test
	public void checkAllIfsOfValidSFunction() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("B");
		assertEquals(true, output);

		output = id.validateIdentifier("Z");
		assertEquals(true, output);
		
		output = id.validateIdentifier("a");
		assertEquals(true, output);
		

		output = id.validateIdentifier("`"); // it's lower than lowerCase A
		assertEquals(false, output);
		

		output = id.validateIdentifier("@"); // it's lower than upperCase A
		assertEquals(false, output);
	}
	

	@Test
	public void checkAllIfsOfValidFFunction() {
		Identifier id = new Identifier();
		boolean output;
		output = id.validateIdentifier("BB");
		assertEquals(true, output);

		output = id.validateIdentifier("ZZ");
		assertEquals(true, output);
		
		output = id.validateIdentifier("aa");
		assertEquals(true, output);

		output = id.validateIdentifier("``"); // it's lower than lowerCase A
		assertEquals(false, output);

		output = id.validateIdentifier("@@"); // it's lower than upperCase A
		assertEquals(false, output);

		output = id.validateIdentifier("//"); // it's lower than 0 of ascii code
		assertEquals(false, output);

		output = id.validateIdentifier("88"); // it's lower than 0 of ascii code
		assertEquals(false, output);
	}
	
}
