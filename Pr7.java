import java.security.SecureRandom;
import java.util.*;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;
import javax.xml.bind.DatatypeConverter;

class symmetric 
{ 
    private static final String AES = "AES";

    private static final String AES_CIPHER_ALGORITHM = "AES/CBC/PKCS5PADDING";
 
     //private static String stringkey;
    
    public static SecretKey createAESKey() throws Exception
    {
        SecureRandom securerandom= new SecureRandom();
        
        KeyGenerator keygenerator= KeyGenerator.getInstance(AES);
 
        keygenerator.init(securerandom);
        
        SecretKey key= keygenerator.generateKey();
        
        //stringkey=Base64.getEncoder().encodeToString(key.getEncoded());
        
        return key;
    }

    public static byte[] createInitializationVector()
    {
        byte[] initializationVector = new byte[16];
        
        SecureRandom secureRandom = new SecureRandom();
        
        secureRandom.nextBytes(initializationVector);
        
        //System.out.println("IV:" + initializationVector);
        
        return initializationVector;
    }
 
    public static byte[] do_AESEncryption(String plainText,SecretKey secretKey,byte[] initializationVector) throws Exception
    {
        Cipher cipher= Cipher.getInstance(AES_CIPHER_ALGORITHM);
 
        IvParameterSpec ivParameterSpec= new IvParameterSpec(initializationVector);
 
        cipher.init(Cipher.ENCRYPT_MODE,secretKey,ivParameterSpec);
 
        return cipher.doFinal(plainText.getBytes());
    }
 
 
    public static String do_AESDecryption(byte[] cipherText,SecretKey secretKey,byte[] initializationVector)throws Exception
    {
        Cipher cipher= Cipher.getInstance(AES_CIPHER_ALGORITHM);
 
        IvParameterSpec ivParameterSpec= new IvParameterSpec(initializationVector);
 
        cipher.init(Cipher.DECRYPT_MODE,secretKey,ivParameterSpec);
 
        byte[] result = cipher.doFinal(cipherText);
 
        return new String(result);
    }
 
    public static void main(String args[]) throws Exception
    {
        SecretKey Symmetrickey = createAESKey();
 
        System.out.println("\n\n\t\t\t******************Output******************\n");    
        
        System.out.println("The Symmetric Key is :"+ DatatypeConverter.printHexBinary(Symmetrickey.getEncoded()));
        System.out.println("-------------------------------------------------------\n");    
        //System.out.println("String key:" + stringkey);
        
        byte[] initializationVector = createInitializationVector();
 
        String plainText = "20BCE519_20BCE523_20BCE526.";
 
        byte[] cipherText = do_AESEncryption(plainText,Symmetrickey,initializationVector);
 
        System.out.println("The ciphertext or "+ "Encrypted Message is: "+ DatatypeConverter.printHexBinary(cipherText));
        
        System.out.println("-------------------------------------------------------\n");
        
        String decryptedText= do_AESDecryption(cipherText,Symmetrickey,initializationVector);
        
        System.out.println("Your original message is: "+ decryptedText);
    }
}