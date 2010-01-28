//
//  JNITest2.java
//  JNITest2
//
//  Created by Marco Gillies on 08/01/2010.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//
package Piavca;

import java.util.*;

public class Piavca {
	
    //public static void main (String args[]) {
	// insert code here...
    //    System.out.println("Hello World!");
    //}
	
	public static float otherTest(float a)
	{
		return 2*a;
	}
	
	static { System.loadLibrary("PiavcaBase");}
}
