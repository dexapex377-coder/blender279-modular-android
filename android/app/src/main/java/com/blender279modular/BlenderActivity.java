package com.blender279modular;

import android.app.Activity;
import android.os.Bundle;
import android.view.SurfaceView;
import android.view.SurfaceHolder;
import android.view.MotionEvent;
import android.view.KeyEvent;
import android.util.Log;
import android.content.Context;

public class BlenderActivity extends Activity implements SurfaceHolder.Callback {
    static {
        System.loadLibrary("blender279_modular");
    }

    private SurfaceView surfaceView;
    private BlenderSurfaceRenderer renderer;
    private BlenderInputHandler inputHandler;

    // Native methods
    private native void nativeInit(String homePath, String configPath);
    private native void nativeResize(int width, int height);
    private native void nativeRender();
    private native void nativeTouchEvent(int action, float x, float y, int pointerId);
    private native void nativeKeyEvent(int keyCode, int unicodeChar, boolean down);
    private native void nativePause();
    private native void nativeResume();
    private native void nativeDestroy();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Get paths
        String homePath = getFilesDir().getAbsolutePath();
        String configPath = getCacheDir().getAbsolutePath();
        
        // Initialize native
        nativeInit(homePath, configPath);
        
        // Create surface view
        surfaceView = new SurfaceView(this);
        surfaceView.getHolder().addCallback(this);
        setContentView(surfaceView);
        
        // Create renderer
        renderer = new BlenderSurfaceRenderer();
        
        // Create input handler
        inputHandler = new BlenderInputHandler(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        Log.i("Blender279", "Surface created");
        renderer.start(holder);
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        Log.i("Blender279", "Surface changed: " + width + "x" + height);
        nativeResize(width, height);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        Log.i("Blender279", "Surface destroyed");
        renderer.stop();
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return inputHandler.onTouchEvent(event);
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        return inputHandler.onKeyDown(keyCode, event);
    }

    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
        return inputHandler.onKeyUp(keyCode, event);
    }

    @Override
    protected void onPause() {
        super.onPause();
        nativePause();
        renderer.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        nativeResume();
        renderer.onResume();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        nativeDestroy();
    }
}