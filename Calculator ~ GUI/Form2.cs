using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Calculator___GUI
{
    public partial class ProgrammerCalculatorForm : Form
    {
        public ProgrammerCalculatorForm()
        {
            InitializeComponent();
        }

        private void fixedSize(object sender, EventArgs e)
        {

            this.Size = new Size(344, 322);
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            this.Input.Text = "";
            this.output.Text = "output";
        }

        private void ProgrammerCalculatorForm_Load(object sender, EventArgs e)
        {
            this.OperationType.SelectedItem = "Decimal";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += "A";
            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += "B";
            }
        }

        private void button12_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += "C";
            }
        }

        private void button11_Click_1(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += "E";
            }
        }

        private void button10_Click_1(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += "F";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += 1;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += 2;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += 3;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15)
            {
                this.Input.Text += 4;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += 5;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15){
                this.Input.Text += 6;
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15)
            {
                this.Input.Text += 7;
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15)
            {
                this.Input.Text += 8;
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15)
            {
                this.Input.Text += 9;
            }
        }

        private void buttonD_Click(object sender, EventArgs e)
        {
            if (this.Input.Text.Length <= 15)
            {
                this.Input.Text += "D";
            }
        }


        private void button0_Click(object sender, EventArgs e)
        {
            if(this.Input.Text.Length <= 15){
                this.Input.Text += 0;
            }
        }

        private void buttonEriser_Click(object sender, EventArgs e){

            char[] textVal = this.Input.Text.ToCharArray();
            this.Input.Text = "";
            for (int i = 0 ; i < textVal.Length - 1 ; i += 1){
                this.Input.Text += textVal[i];
            }
        
        }

        private void ToBin_CheckedChanged()
        {
            this.Input.Text = "";
            this.button2.Enabled = false;
            this.button3.Enabled = false;
            this.button4.Enabled = false;
            this.button5.Enabled = false;
            this.button6.Enabled = false;
            this.button7.Enabled = false;
            this.button8.Enabled = false;
            this.button9.Enabled = false;
            this.buttonA.Enabled = false;
            this.buttonB.Enabled = false;
            this.buttonC.Enabled = false;
            this.buttonD.Enabled = false;
            this.buttonE.Enabled = false;
            this.buttonF.Enabled = false;

        }

        private void ToDec_CheckedChanged()
        {
            this.Input.Text = "";
            this.button2.Enabled = true;
            this.button3.Enabled = true;
            this.button4.Enabled = true;
            this.button5.Enabled = true;
            this.button6.Enabled = true;
            this.button7.Enabled = true;
            this.button8.Enabled = true;
            this.button9.Enabled = true;
            this.buttonA.Enabled = false;
            this.buttonB.Enabled = false;
            this.buttonD.Enabled = false;
            this.buttonC.Enabled = false;
            this.buttonE.Enabled = false;
            this.buttonF.Enabled = false;
        }

        private void ToHex_CheckedChanged()
        {
            this.Input.Text = "";
            this.button2.Enabled = true;
            this.button3.Enabled = true;
            this.button4.Enabled = true;
            this.button5.Enabled = true;
            this.button6.Enabled = true;
            this.button7.Enabled = true;
            this.button8.Enabled = true;
            this.button9.Enabled = true;
            this.buttonA.Enabled = true;
            this.buttonB.Enabled = true;
            this.buttonC.Enabled = true;
            this.buttonD.Enabled = true;
            this.buttonE.Enabled = true;
            this.buttonF.Enabled = true;
        }

        private void ToOct_CheckedChanged()
        {
            this.Input.Text = "";
            this.button2.Enabled = true;
            this.button3.Enabled = true;
            this.button4.Enabled = true;
            this.button5.Enabled = true;
            this.button6.Enabled = true;
            this.button7.Enabled = true;
            this.button8.Enabled = false;
            this.button9.Enabled = false;
            this.buttonA.Enabled = false;
            this.buttonB.Enabled = false;
            this.buttonC.Enabled = false;
            this.buttonD.Enabled = false;
            this.buttonE.Enabled = false;
            this.buttonF.Enabled = false;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e){
        }

        private void OperationType_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(OperationType.SelectedIndex == 0) {
                ToDec_CheckedChanged();
            }
            if (OperationType.SelectedIndex == 1)
            {
                ToBin_CheckedChanged();
            }
            if (OperationType.SelectedIndex == 2)
            {
                ToHex_CheckedChanged();
            }
            if (OperationType.SelectedIndex == 3)
            {
                ToOct_CheckedChanged();
            }

        }

        private void buttonSum_Click(object sender, EventArgs e)
        {

            try{

                // define sum varible 
                ulong sum;

                // if detected converting to "Octal"
                if (OperationType.SelectedItem.ToString() == "Octal")
                {
                    output.Text = Convert.ToInt32(Input.Text, 8).ToString();
                }

                // if detected converting to "HexaDecimal"
                if (OperationType.SelectedItem.ToString() == "HexaDecimal")
                {
                    sum = Convert.ToUInt64(Input.Text, 16);
                    output.Text = sum.ToString();
                }

                // if detected converting to "Decimal"
                if (OperationType.SelectedItem.ToString() == "Decimal")
                {
                    sum = Convert.ToUInt64(Input.Text);
                    output.Text = sum.ToString();
                }

                // if detected converting to "Binary"
                if (OperationType.SelectedItem.ToString() == "Binary")
                {
                    output.Text = Convert.ToInt32(Input.Text, 2).ToString();
                }

            }
            catch (Exception error)
            {
                MessageBox.Show("Error :" + error, "Error");
            }

        }

    }
}
