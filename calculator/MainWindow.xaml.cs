using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace calculator
{

    public partial class MainWindow : Window
    {

        /*
            to store the last "textbox input" user click on it
            important for us to insert new inputs in right "textbox"
            expressions_input   = 0
            functions_input     = 1
            variables_input     = 2
        */
        private static short current_active_input = 0;

        public MainWindow()
        {
            InitializeComponent();
        }

        public void LogMessage(string message)
        {
            MessageBox.Show(message);
        }

        public void AddNumberToExpression(string value){

            switch( current_active_input ){

                case 0 : { x: Expressions_input.Text += value; } break;

                case 1 : { x: Functions_input.Text   += value; } break;

                case 2 : { x: Variables_input.Text   += value; } break;

            }

        }

        public void AddCharToExpression(char value){

            switch (current_active_input){

                case 0: { x: Expressions_input.Text += value; } break;

                case 1: { x: Functions_input.Text += value; } break;

                case 2: { x: Variables_input.Text += value; } break;

            }
    
        }

        public void AddOperatorToExpression(char value)
        {

            switch (current_active_input){

                case 0: { x: Expressions_input.Text += value; } break;

                case 1: { x: Functions_input.Text += value; } break;

                case 2: { x: Variables_input.Text += value; } break;

            }

        }

        public void AddValueToExpression(double value){

            switch (current_active_input) {

                case 0: { x: Expressions_input.Text += value; } break;

                case 1: { x: Functions_input.Text += value; } break;

                case 2: { x: Variables_input.Text += value; } break;

            }

        }

        private void N0_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("0");
        }

        private void N1_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("1");
        }

        private void N2_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("2");
        }

        private void N3_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("3");
        }

        private void N4_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("4");
        }

        private void N5_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("5");
        }

        private void N6_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("6");
        }

        private void N7_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("7");
        }

        private void N8_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("8");
        }

        private void N9_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression("9");
        }

        private void FloatPoint_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddCharToExpression('.');
        }


        private void BracketOpen_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddCharToExpression('(');
        }

        private void BracketClose_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddCharToExpression(')');
        }

        private void FunctionBracket_OpenButton_OnClick(object sender, RoutedEventArgs e)
        {
            AddCharToExpression('{');
        }

        private void FunctionBracket_CloseButton_OnClick(object sender, RoutedEventArgs e)
        {
            AddCharToExpression('}');
        }


        private void OperatorPlus_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddOperatorToExpression('+');
        }

        private void OperatorMinus_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddOperatorToExpression('-');
        }

        private void OperatorMultiplay_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddOperatorToExpression('*');
        }

        private void OperatorMod_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddOperatorToExpression('%');
        }

        private void OperatorDivision_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddOperatorToExpression('/');
        }

        private void OperatorPower_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddOperatorToExpression('^');
        }

        private void Pi_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddValueToExpression(Math.PI);
        }

        private void Euler_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddValueToExpression(Math.E);
        }

        private void Clear_Button_OnClick(object sender, RoutedEventArgs e){

          
                switch (current_active_input){

                    case 0: {

                        if (Expressions_input.Text.Length > 0) {

                            int text_len = (int)(Expressions_input.Text.Length - 1);
                            x: Expressions_input.Text = Expressions_input.Text.Substring(0, text_len);

                        }

                    } break;

                    case 1: {

                        if (Functions_input.Text.Length > 0){

                            int text_len = (int)(Functions_input.Text.Length - 1);
                            x: Functions_input.Text = Functions_input.Text.Substring(0, text_len);

                        }

                    } break;

                    case 2: {

                        if (Variables_input.Text.Length > 0){

                            int text_len = (int)(Variables_input.Text.Length - 1);
                            x: Variables_input.Text = Variables_input.Text.Substring(0, text_len);

                        }
         
                    } break;

                }

            

        }

        private void ClearAll_Button_OnClick(object sender, RoutedEventArgs e){

            switch (current_active_input){

                case 0: { x: Expressions_input.Text = ""; } break;

                case 1: { x: Functions_input.Text = ""; } break;

                case 2: { x: Variables_input.Text = ""; } break;

            }

        }

        private void Save_Button_OnClick(object sender, RoutedEventArgs e)
        {
            LogMessage("Save button clicked");

        }
        private void Load_Button_OnClick(object sender, RoutedEventArgs e)
        {
            LogMessage("Load button clicked");

        }

        private void Equal_Button_OnClick(object sender, RoutedEventArgs e)
        {
            LogMessage("Equal button clicked");
        }

        private void SetActiveInput(object sender, RoutedEventArgs e){

            String tag = (String)((TextBox)sender).Tag;

            current_active_input = (short)(tag[0] - '0');

        }

    }
}
