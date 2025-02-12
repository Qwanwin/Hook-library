package com.qwanwin.hook;
 
import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.view.Gravity;
import android.graphics.Color;

public class MainActivity extends Activity { 
     
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        TextView textView = new TextView(this);
        textView.setText("Hallo Saya Qwanwin");
        textView.setGravity(Gravity.CENTER);
        textView.setTextSize(24);
        textView.setTextColor(Color.BLACK); 
        
        setContentView(textView);
    }
}