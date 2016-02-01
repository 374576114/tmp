public class TestJni{
	public native void display(String strName);
	
	static {
		System.loadLibrary("testjni");
	}

	public static void main(String[] args){
		TestJni jni = new TestJni();
		jni.display("abcdkdlj");
	}
}
