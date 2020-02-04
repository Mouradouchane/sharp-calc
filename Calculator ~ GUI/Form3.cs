using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator___GUI
{
    public partial class aboutForm : Form
    {
        public aboutForm()
        {
            InitializeComponent();
        }

        private void githubButton_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://github.com/Mouradouchane/CsharpCalculatorGUI");

        }

        private void aboutForm_Resize(object sender, EventArgs e){

            // call fixed size function if user try to resize window
            fixedSize(sender, e);

        }

        private void fixedSize(object sender, EventArgs e){

            this.Size = new Size(269, 208);

        }

    }
}
