package intercon.example.com.intercon;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.content.IntentFilter;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Set;

import static android.widget.Toast.makeText;

public class MainActivity extends AppCompatActivity {
    BluetoothAdapter bluetoothAdapter; //Class needed to instantiate the system bluetooth
    ArrayList<BluetoothDevice> pairedDeviceArrayList;
    ArrayAdapter<String> pairedDeviceAdapter;
    ListView pairedDevices;
    ArrayList<BluetoothDevice> BtList;
    TextView textInfo;
    BluetoothDevice chosenDev =  null;
    IntentFilter mIntentFilter;
    private int flag1 = 0;
    private Intent intserv;

    private static final int REQUEST_ENABLE_BT = 1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(getBaseContext(),"Tenha um bom dia!!",Toast.LENGTH_LONG).show();
            }
        });
        intserv = new Intent(this,BtService.class);
        bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        if (bluetoothAdapter == null) {
            makeText(this,
                    "Bluetooth is not supported on this hardware platform",
                    Toast.LENGTH_LONG).show();
            finish();

            return;
        }
    }

    @Override
    //This is a method that is called in mine activity result callback, from when i call
    //bluetooth to enable with starAnactivityforresult()
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(requestCode==REQUEST_ENABLE_BT){
            if(resultCode == Activity.RESULT_OK){
                setup();
            }else{
                Toast.makeText(this,
                        "BlueTooth NOT enabled",
                        Toast.LENGTH_SHORT).show();
                finish();
            }
        }
    }
    public void setup() {

        final Intent intent = new Intent(this, BtService.class);
        Set<BluetoothDevice> btPaired = bluetoothAdapter.getBondedDevices(); //Here we get a set(conjunto da mtm)
        //of the bt bonded devices, the ones that are paired
        ArrayList<String> deviceName = new ArrayList<>(); // here we create a array list to list the name of the devices
        // that are paired
        if (btPaired.size() > 0) {
            for (BluetoothDevice Btdev : btPaired) { //here we use a different kind of for
                //He goes through the amount of elements in a set passing their respective values to a element
                //to be used inside the loop
                deviceName.add(Btdev.getName());
            }
            pairedDeviceAdapter = new ArrayAdapter<String>(this,
                    android.R.layout.simple_list_item_1, deviceName); //addapting my arraylist so i can use it
            //to make a listview, so the user can choose wich device he wants to pair
            //pairedDevices = (ListView) findViewById(R.id.PairedDevices);
            pairedDevices.setAdapter(pairedDeviceAdapter); //getting the listview real
            pairedDevices.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                //here we call a method thats a listener to get the bluetooth
                @Override
                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                    Set<BluetoothDevice> btPaired = bluetoothAdapter.getBondedDevices();
                    String device =
                            (String) parent.getItemAtPosition(position);
                    for (BluetoothDevice btPair : btPaired) {
                        if(device.equals(btPair.getName())){
                            chosenDev = btPair;
                        }

                    }

                  /* Toast.makeText(MainActivity.this,
                            "Name: " + chosenDev.getName() + "\n"
                                    + "Address: " + chosenDev.getAddress() + "\n"
                                    + "BondState: " + chosenDev.getBondState() + "\n"
                                    + "BluetoothClass: " + chosenDev.getBluetoothClass() + "\n"
                                    + "Class: " + chosenDev.getClass(),
                            Toast.LENGTH_LONG).show();
                            */
                    intent.putExtra("Device",chosenDev);
                    intent.putExtra("pairing",1);
                    startService(intent);
                }

            });


        }
    }
}
