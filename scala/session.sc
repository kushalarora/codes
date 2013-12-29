package week1
object session {
  def abs(x: Double) = if (x < 0) -x else x;      //> abs: (x: Double)Double
 /*
Following code shows two important concepts:

1. Closures:
	i. The variable inside the braces are not visible outside
	ii. Variable outside the braces will be visible unless and untill explicitly overloaded

2. Function can contain functions and can return functions. They are first class members
*/

  def sqrt(x: Double): Double = {

    def sqrIter(guess: Double): Double =
      if (isGoodEnough(guess)) guess
      else sqrIter(improve(guess))

    def isGoodEnough(guess: Double) =
      abs(guess * guess - x) / x < 1e-5

    def improve(guess: Double) = (guess + x / guess) / 2
    sqrIter(1)
  }                                               //> sqrt: (x: Double)Double
  sqrt(2)                                         //> res0: Double = 1.4142156862745097
  sqrt(100)                                       //> res1: Double = 10.000000000139897

  /*
  Factorial Function as a tail recursion
  */
  def factorial(a: Int): Int = {
    def loop(acc: Int, x: Int): Int =
      if (x == 0) acc
      else loop(acc * x, x - 1)
    loop(1, a)
  }                                               //> factorial: (a: Int)Int

  factorial(4)                                    //> res2: Int = 24
  
  
  
  // Anonymous Functions
  // F in following function can be passed as a function or as a
  // syntactic sugar with anonymous function.
  // These are like lambda functions
  def sum(f:Int => Int, a:Int, b:Int):Int =
  	if (a > b) 0
  	else f(a) + sum(f, a + 1, b)              //> sum: (f: Int => Int, a: Int, b: Int)Int
  	
 
 sum(x => x, 1, 10)                               //> res3: Int = 55
 sum(factorial, 1, 5)                             //> res4: Int = 153
 
 
 // Tail recursion form of Sum
 def sumT(f:Int => Int, a:Int, b:Int) = {
 	def loop(acc:Int, a:Int):Int = {
 		if (a > b) acc
 			else loop(acc + a, a + 1)
 		}
 	loop(0, a)
 	}                                         //> sumT: (f: Int => Int, a: Int, b: Int)Int
 	
 	sumT(x => x, 1, 10)                       //> res5: Int = 55
 	
 	// Closure again. Returning sum as a function.
 	// What this does is it take manipulating function as input
 	// return function that returns sum of that manipulating function
 	def sumC(f:Int => Int): (Int, Int) => Int = {
 		def sumF(x:Int, y:Int): Int =
 			if (x > y) 0 else
 				x + sumF(x + 1, y)
 		sumF
	}                                         //> sumC: (f: Int => Int)(Int, Int) => Int
	sumC(x => x)(1, 10)                       //> res6: Int = 55
	
	
	// There is a simpler way of writing this
	// A syntactic sugar way
	
	def sumD(f:Int => Int)(a:Int, b:Int): Int =
		if (a > b) 0 else 	f(a) + sumD(f)(a + 1, b)
                                                  //> sumD: (f: Int => Int)(a: Int, b: Int)Int
 	sumD(x => x)(1, 10)                       //> res7: Int = 55
 	
 	
 	// Basically any function of type
 	// def f(args1)(args2)(args3)...(argsN) = {def g(argsN) = E;g}
 	// or using anonymous function {(argsN => E }
 	
 	// def f(args1)(args2)(args3)....(argsN) = E
 	// def f = args1 => (args2 => (args3 => .. => (argsN => E)).. ))
 	
 	// This implies f(args1) returns args2 => .. (argsN => E).. ))
 	
 	// And eventually
 	// f(args1)(args2)(args3)..(argsN-1) = argsN => E
 	// i.e the chaining of functions (or currying as it is called, upto N - 1 returns
 	// ultimate functions argsN => E
 	
 	def product(f: Int => Int)(a:Int, b:Int): Int =
 		if (a > b) 1 else f(a) * product(f)(a+1, b)
                                                  //> product: (f: Int => Int)(a: Int, b: Int)Int
 
 	product(x => x)(1, 5)                     //> res8: Int = 120
 	
 	def factorialP(a:Int):Int = product(x => x)(1, a)
                                                  //> factorialP: (a: Int)Int
                                                 
 	factorialP(5)                             //> res9: Int = 120
 		
 		
 		
 	// Fixed Point
 	// Solution to x = f(x).
 	// Can be computed by recursively applying f on result
 	// f(x), ff(x), fff(x)..
 	
 	def fixedPoint(f:Double => Double)(firstGuess:Double):Double = {
 		def threshold:Double = .00001
 	
 		def isCloseEnough(guess:Double):Boolean =
 			abs(guess - firstGuess) / firstGuess < threshold
 			
 		def iterate(guess:Double): Double = {
 			println("guess is ", guess);
 			if (isCloseEnough(guess)) guess	else iterate(f(guess))
 		}
 			
 		iterate(f(firstGuess))
 	}                                         //> fixedPoint: (f: Double => Double)(x: Double)Double
 	
 	fixedPoint(x => 1 + x/2)(1)               //> (guess is ,1.0)
                                                  //| res10: Double = 1.0
 }
 