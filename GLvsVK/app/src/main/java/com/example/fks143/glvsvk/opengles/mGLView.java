package com.example.fks143.glvsvk.opengles;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by FKS143 on 2016/8/27.
 */
public class mGLView extends GLSurfaceView {

    private MRenderer renderer;

    public mGLView(Context context) {
        super(context);

        setEGLContextClientVersion(3);
        setEGLConfigChooser(8, 8, 8, 8, 16, 0);

        renderer = new MRenderer(context);
        setRenderer(renderer);
    }

    public void background() {
        renderer.pause();
        mGLLib.kill();
    }

    private static class MRenderer implements Renderer {

        private boolean paused;

        public MRenderer(Context context) {
            paused = false;
        }

        public void onDrawFrame(GL10 gl) {
            if (!paused) {
                mGLLib.step();
            }
        }

        public void onSurfaceChanged(GL10 gl, int width, int height) {
            mGLLib.resize(width, height);
        }

        public void onSurfaceCreated(GL10 gl, EGLConfig config) {
            mGLLib.init();
        }

        public void pause() {
            paused = true;
        }
    }

}
