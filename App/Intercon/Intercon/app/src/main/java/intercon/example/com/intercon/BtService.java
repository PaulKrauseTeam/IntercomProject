package intercon.example.com.intercon;

/**
 * Created by claudio on 08/11/2017.
 */
/**
 * Created by claudio on 27/09/2016.
 */

import android.app.Service;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Looper;
import android.os.Message;
import android.os.Process;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.LocalBroadcastManager;
import android.widget.Toast;

import static android.widget.Toast.makeText;


import android.app.Service;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Looper;
import android.os.Message;
import android.os.Process;
import android.widget.ArrayAdapter;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.UUID;

import static android.widget.Toast.makeText;

/**
 * Created by claudio on 13/09/2016.
 */
public class BtService extends Service {
    private static final int REQUEST_ENABLE_BT = 1;

    private Looper mServiceLooper; //Used to run a message queue for a thread,
    public int opera;
    private boolean first_connect = true;
    private ServiceHandler  mServiceHandler; //Delivers the msg from the main thread to the parallel thread
    private BluetoothSocket bluetoothSocket = null;
    private UUID myUUID;
    InputStream in = null;
    OutputStream out = null;
    private final String UUID_STRING_WELL_KNOWN_SPP =
            "00001101-0000-1000-8000-00805F9B34FB";
    private  BluetoothSocket mmSocket;
    private final class ServiceHandler extends Handler {
        private final InputStream InStream = null;
        public ServiceHandler(Looper looper){
            super(looper);
        }
        @Override
        public void handleMessage(Message msg){

            if(msg.arg1 == 1){
                mmSocket = null;
                myUUID = UUID.fromString(UUID_STRING_WELL_KNOWN_SPP);
                int sucess =0;
                String eMessage = null;
                BluetoothDevice ToConnectDev = (BluetoothDevice) msg.obj;
                try {
                    bluetoothSocket = ToConnectDev.createRfcommSocketToServiceRecord(myUUID);
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                try {
                    bluetoothSocket.connect();
                    sucess = 1;
                    first_connect = true;
                    mmSocket = bluetoothSocket;
                } catch (IOException e) {
                    e.printStackTrace();
                    eMessage = e.getMessage();
                    sucess = 0;
                    try {
                        bluetoothSocket.close();
                    } catch (IOException e1) {
                        // TODO Auto-generated catch block
                        e1.printStackTrace();
                    }
                }

                Intent intent = new Intent();
                intent.putExtra("sucess",sucess);
                intent.putExtra("socket",bluetoothSocket.hashCode());
                intent.putExtra("eMessage",eMessage);
                intent.setAction("getting_first_broadcast_claudio_package");
                sendBroadcast(intent);

            }
            else if(msg.arg1 == 2){
                if(first_connect) {
                    first_connect = false;
                    try {
                        in = bluetoothSocket.getInputStream();
                        out = bluetoothSocket.getOutputStream();
                    } catch(IOException e){
                    }

                }
                final byte[] to_send = (byte[]) msg.obj;
                try{
                    out.write(to_send);
                } catch (IOException e){}
            }
            else if(msg.arg1 == 3) {
                final byte[] send_bar = (byte[]) msg.obj;
                try {
                    out.write(send_bar);
                } catch (IOException e) {
                }
            }




        }


    }

    public BtService() {
        super();
    }


    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {

        HandlerThread thread = new HandlerThread("ServiceStartArguments",
                Process.THREAD_PRIORITY_BACKGROUND);
        thread.start();
        mServiceLooper = thread.getLooper();
        mServiceHandler = new ServiceHandler(mServiceLooper);
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Message msg = mServiceHandler.obtainMessage();
        if(intent.getIntExtra("pairing",0) == 1) {
            BluetoothDevice ToConnectDev = null;
            msg.arg1 = intent.getIntExtra("pairing",0);
            ToConnectDev = intent.getParcelableExtra("Device");
            //  Toast.makeText(this,"Trying to connect to " + ToConnectDev.getName(),Toast.LENGTH_SHORT).show();
            msg.obj = ToConnectDev;
        }
        if(intent.getIntExtra("message",0)== 2){
            msg.arg1 = intent.getIntExtra("message",0);
            msg.obj = intent.getByteArrayExtra("effect");
        }
        else if(intent.getIntExtra("message",0) == 3) {
            msg.arg1 = intent.getIntExtra("message", 0);
            msg.obj = intent.getByteArrayExtra("bar_changed");
        }
        mServiceHandler.sendMessage(msg);

        return START_NOT_STICKY; //flag para dizer que se meu servico for morto de alguma forma não recomecar
    }

    @Override
    public void onDestroy(){
        try {
            mmSocket.close();
            bluetoothSocket.close();
        } catch (IOException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }
        makeText(this,"Bluetooth Disconnected",Toast.LENGTH_SHORT).show();
    }


}