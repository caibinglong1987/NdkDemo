package com.hx.hexintegrated;

/**
 * @author caibinglong
 *         date 2019/7/12.
 *         desc desc
 */

public class HexNative {

    static {
       // System.loadLibrary("HexLibrary");
    }

    public static native String encryption(String deviceId);
}
