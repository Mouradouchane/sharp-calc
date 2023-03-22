using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text;
using System.Runtime.InteropServices;


namespace Calculator___GUI
{
    public static class lib {
        
        [DllImport("operations.dll" , CallingConvention = CallingConvention.Cdecl)]
        public static extern void parse_expression(   
            [MarshalAs(UnmanagedType.LPWStr)]
            ref string expression_string_lenght
        );

    }

    static class Program {

        [STAThread]

        static void Main(){

            string vl = "this is test value";
            lib.parse_expression( ref vl );


            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            MainForm main = new MainForm();
            main.Text = vl.ToString();
            Application.Run( main );

        }
    }
}
