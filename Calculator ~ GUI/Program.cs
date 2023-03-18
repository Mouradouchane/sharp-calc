using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Calculator___GUI
{
    static class Program {

        [ DllImport( "operations.dll" ) ]
        public static extern int parser_test();

        static int parser_value = parser_test();

        [STAThread]

        static void Main(){

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

     

            Application.Run(
                new MainForm()
            );

        }
    }
}
