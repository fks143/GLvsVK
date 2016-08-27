package com.example.fks143.glvsvk.opengles;

/**
 * Created by FKS143 on 2016/8/27.
 */
public class mGLLib {

    static {
        System.loadLibrary("mjni");
    }

    public static native void resize(int width, int height);
    public static native void step();
    public static native void init();
    public static native void kill();
    
}
