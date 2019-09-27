using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class Move : MonoBehaviour
{
    const string DLL_NAME = "SIMPLEPLUGIN";


    // Update is called once per frame
    void Update()
    {
        // Save and Load
        if (Input.GetKeyDown(KeyCode.O))
            Save();
        else if (Input.GetKeyDown(KeyCode.L))
            Load();

        // Movement controls
        if (Input.GetKey(KeyCode.W))
            transform.position += Vector3.forward;
        else if (Input.GetKey(KeyCode.S))
            transform.position += Vector3.back;
        else if (Input.GetKey(KeyCode.A))
            transform.position += Vector3.left;
        else if (Input.GetKey(KeyCode.D))
            transform.position += Vector3.right;
    }

    void Save()
    {
        Debug.Log("Saving");

        Vector3 pos = transform.position;
        float[] posArr = { pos.x, pos.y, pos.z };
        savePos("pos.txt", posArr);

        Debug.Log("Saved: " + pos.ToString());
    }

    void Load()
    {
        Debug.Log("Loading");

        loadPos("pos.txt");
        Vector3 pos;
        int size = 3;

        //byte[] posArr = new byte[size];
        float[] posArr = new float[size];

        Marshal.Copy(getPos(), posArr, 0, size);

        pos.x = posArr[0];
        pos.y = posArr[1];
        pos.z = posArr[2];

        transform.position = pos;

        Debug.Log("Loaded: " + pos.ToString());
    }

    [DllImport(DLL_NAME)]
    private static extern void savePos(string filePath, float[] pos);

    [DllImport(DLL_NAME)]
    private static extern void loadPos(string filePath);

    [DllImport(DLL_NAME)]
    private static extern System.IntPtr getPos();
}
