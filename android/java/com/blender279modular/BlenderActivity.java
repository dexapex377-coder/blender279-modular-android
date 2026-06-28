package com.blender279modular;

import android.app.NativeActivity;
import android.content.res.Configuration;
import android.graphics.PixelFormat;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;

public class BlenderActivity extends NativeActivity implements SurfaceHolder.Callback {
    private static final String TAG = "Blender279Modular";
    private SurfaceView surfaceView;
    private boolean surfaceCreated = false;

    static {
        System.loadLibrary("blender279_modular");
    }

    public native boolean init(String homePath);
    public native void setSurface(SurfaceHolder holder);
    public native void onTouch(int action, float x, float y, int pointerId);
    public native void shutdown();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Fullscreen
        getWindow().setFormat(PixelFormat.RGBA_8888);
        
        surfaceView = new SurfaceView(this);
        surfaceView.getHolder().addCallback(this);
        surfaceView.setFocusable(true);
        surfaceView.setFocusableInTouchMode(true);
        surfaceView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                int action = event.getActionMasked();
                int pointerId = event.getPointerId(event.getActionIndex());
                float x = event.getX(event.getActionIndex());
                float y = event.getY(event.getActionIndex());
                
                if (surfaceCreated) {
                    onTouch(action, x, y, pointerId);
                }
                return true;
            }
        });
        
        setContentView(surfaceView);
        
        // Initialize with app files directory
        String homePath = getFilesDir().getAbsolutePath();
        Log.i(TAG, "Home path: " + homePath);
        init(homePath);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        surfaceCreated = true;
        setSurface(holder);
        Log.i(TAG, "Surface created");
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        Log.i(TAG, "Surface changed: " + width + "x" + height);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        surfaceCreated = false;
        Log.i(TAG, "Surface destroyed");
    }

    @Override
    protected void onDestroy() {
        shutdown();
        super.onDestroy();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }
}