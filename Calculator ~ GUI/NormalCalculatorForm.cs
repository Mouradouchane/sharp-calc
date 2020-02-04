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
    public partial class NormalCalculatorForm : Form
    {
        public NormalCalculatorForm()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void fixedSize(object sender, EventArgs e)
        {

            this.Size = new Size(249, 299);
        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void button0_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 0;
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void buttonDot_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += ".";
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += "+";
        }

        private void buttonMod_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += "%";
        }

        private void buttonSum_Click(object sender, EventArgs e)
        {
            try {
                DataTable dt = new DataTable();
                var result = dt.Compute(this.InpOutReslt.Text, "");
                this.InpOutReslt.Text = result.ToString();
            }
            catch(Exception error) {
                MessageBox.Show("Error : " + error);
            }

        }

        private void buttonPower_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text +="*";
        }

        private void buttonDivide_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += "/";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 6;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 1;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 2;
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 3;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 4;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 5;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 7;
        }

        private void button8_Click_1(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 8;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text += 9;
        }

        private void NormalCalculatorForm_Load(object sender, EventArgs e)
        {

        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            this.InpOutReslt.Text = "";
        }

        private void buttonEriser_Click(object sender, EventArgs e)
        {
            try { 

                char[] textChars = this.InpOutReslt.Text.ToCharArray();
                this.InpOutReslt.Text = "";

                for (int i = 0; i < textChars.Length-1 ; i += 1) {
                    this.InpOutReslt.Text += textChars[i];
                }
               
            }
            catch(Exception error) {
                MessageBox.Show(error.ToString(),"Error");
            }
        }
    }
}
