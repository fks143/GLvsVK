package com.example.fks143.glvsvk;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.AlertDialog;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ConfigurationInfo;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

    private Button btn_gl;
    private Button btn_vk;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (detectOpenGLES30()) {
            btn_gl = (Button) findViewById(R.id.btn_gl);
            btn_vk = (Button) findViewById(R.id.btn_vk);

            btn_gl.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    btnOnClick(view);
                }
            });

            btn_vk.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    btnOnClick(view);
                }
            });
        }
    }

    public void btnOnClick(View view) {
        if (view == btn_gl) {
            Intent intent = new Intent(MainActivity.this, GLActivity.class);
            startActivity(intent);
        }
        else if (view == btn_vk) {
            Intent intent = new Intent(MainActivity.this, VKActivity.class);
            startActivity(intent);
        }
    }

    private boolean detectOpenGLES30() {
        ActivityManager am = (ActivityManager)getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo info = am.getDeviceConfigurationInfo();

//        new AlertDialog.Builder(MainActivity.this).setTitle("OpenGL ES Version:")
//                .setMessage(info.reqGlEsVersion)
//                .show();

        return (info.reqGlEsVersion >= 0x30000);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
//        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
