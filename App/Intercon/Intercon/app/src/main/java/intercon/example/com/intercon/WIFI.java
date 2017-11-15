package intercon.example.com.intercon;

import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import android.os.Process;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.os.Handler;
import android.os.HandlerThread;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.RequestFuture;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.io.FileOutputStream;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

public class WIFI extends AppCompatActivity {
    public static final String TAG = "MyTag";
    private Looper mServiceLooper;
    private RequestQueue postRequest,getRequest;
    private FileOutputStream outputStream;
    private final String ServerAddr = "http://www.google.com";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_wifi);

        HandlerThread thread = new HandlerThread("ServiceStartArguments",
                Process.THREAD_PRIORITY_BACKGROUND);
        thread.start();
        mServiceLooper = thread.getLooper();
        getRequest = Volley.newRequestQueue(this);

        Button button = (Button) findViewById(R.id.button7);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(getBaseContext(),"Button CLicked",Toast.LENGTH_SHORT).show();
                StringRequest stringRequest = new StringRequest(Request.Method.GET, ServerAddr,
                        new Response.Listener<String>() {
                            @Override
                            public void onResponse(String response) {
                                // Display the first 500 characters of the response string.

                                Toast.makeText(getApplicationContext(), "Response is: "+ response.substring(0,500),
                                        Toast.LENGTH_LONG).show();
                            }
                        }, new Response.ErrorListener() {
                    @Override
                    public void onErrorResponse(VolleyError error) {

                        Toast.makeText(getApplicationContext(), "That didin't work" ,Toast.LENGTH_LONG).show();
                    }

                });
                stringRequest.setTag(TAG);
// Add the request to the RequestQueue.
                getRequest.add(stringRequest);
            }

        });
    }

    @Override
    protected void onStop () {
        super.onStop();
        if (getRequest != null) {
            getRequest.cancelAll(TAG);
        }
    }

    }
