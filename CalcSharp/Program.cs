using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Calculator___GUI
{
    public static class lib {
        
        [ DllImport( "operations.dll" ) ] public static extern int parser_test();

        [DllImport("operations.dll")] public static extern int operator_test();
    }

    static class Program {

        [STAThread]

        static void Main(){

            int parser_value = lib.parser_test();
            int op_value = lib.operator_test();

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            Application.Run(
                new MainForm()
            );

        }
    }
}
