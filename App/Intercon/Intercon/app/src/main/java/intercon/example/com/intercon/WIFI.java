package intercon.example.com.intercon;

import android.content.Context;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import android.os.Process;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.os.Handler;
import android.os.HandlerThread;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.RequestFuture;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import com.google.zxing.Result;

import org.json.JSONObject;

import java.io.FileOutputStream;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

import me.dm7.barcodescanner.zxing.ZXingScannerView;

public class WIFI extends AppCompatActivity  implements ZXingScannerView.ResultHandler{
    public static final String TAG = "MyTag";
    private Looper mServiceLooper;
    private RequestQueue postRequest,getRequest;
    private FileOutputStream outputStream;
    private String ServerAddr = "http://www.google.com";
    private ZXingScannerView mScannerView;
    private ListView mylistvew;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_wifi);

        HandlerThread thread = new HandlerThread("ServiceStartArguments",
                Process.THREAD_PRIORITY_BACKGROUND);
        thread.start();
        mServiceLooper = thread.getLooper();
        getRequest = Volley.newRequestQueue(this);
        mylistvew = (ListView)findViewById(R.id.list_view);
    }
    public void QRcode(View v){
        Toast.makeText(getBaseContext(),"Button CLicked",Toast.LENGTH_SHORT).show();
        mScannerView = new ZXingScannerView(this);   // Programmatically initialize the scanner view<br />
        setContentView(mScannerView);
        mScannerView.setResultHandler(this); // Register ourselves as a handler for scan results.<br />
        mScannerView.startCamera();         // Start camera


    }

    @Override
    protected void onStop () {
        super.onStop();
        if (getRequest != null) {
            getRequest.cancelAll(TAG);
        }
        mScannerView.stopCamera();   // Stop camera on pause
    }
    JSONObject  myrecievedobj;
    @Override
    public void handleResult(Result rawResult) {
        mScannerView.stopCamera();
        Log.e("Ola","Marilene");
        /*AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setTitle("Resultado QR code");
                builder.setMessage(rawResult.getText());
                AlertDialog alert1 = builder.create();
                alert1.show();*/
        // If you would like to resume scanning, call this method below:<br />
        ServerAddr = rawResult.getText();
        //mScannerView.resumeCameraPreview(this);
        //String Request to server

        JsonObjectRequest jsObjRequest = new JsonObjectRequest
                (Request.Method.GET, ServerAddr, null, new Response.Listener<JSONObject>() {

                    @Override
                    public void onResponse(JSONObject response) {
                        Toast.makeText(getApplicationContext(), "Response is: "+ response.toString(),
                                Toast.LENGTH_LONG).show();
                        myrecievedobj = response;
                    }
                }, new Response.ErrorListener() {

                    @Override
                    public void onErrorResponse(VolleyError error) {
                        // TODO Auto-generated method stub
                        Toast.makeText(getApplicationContext(), "Response is: ",
                                Toast.LENGTH_LONG).show();
                    }
                });
// Add the request to the RequestQueue.
        getRequest.add(jsObjRequest);
        CreateListView(myrecievedobj);
        setContentView(R.layout.activity_wifi);
    }
    public void CreateListView(JSONObject listContent){
        try {
            String firstItem = listContent.getString("title");
        } catch(org.json.JSONException e){
            Toast.makeText(getApplicationContext(), e.toString(),
                    Toast.LENGTH_LONG).show();

        }
    }


}

