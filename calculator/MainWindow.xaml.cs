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

        public MainWindow()
        {
            InitializeComponent();
        }

        public void LogMessage(string message)
        {
            MessageBox.Show(message);
        }

        public void AddNumberToExpression( int value )
        {
            MessageBox.Show($"Button {value} is clicked!");
        }

        public void AddCharToExpression(char value)
        {
            MessageBox.Show($"Button '{value}' is clicked!");
        }

        public void AddOperatorToExpression(char value)
        {
            MessageBox.Show($"Button '{value}' is clicked!");
        }

        public void AddValueToExpression( double value )
        {
            MessageBox.Show($"Button value={value} is clicked!");

        }

        private void N0_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(0);
        }

        private void N1_Button_OnClick(object sender, RoutedEventArgs e){
            AddNumberToExpression(1);
        }

        private void N2_Button_OnClick(object sender, RoutedEventArgs e ) { 
            AddNumberToExpression(2); 
        }

        private void N3_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(3);
        }

        private void N4_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(4);
        }

        private void N5_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(5);
        }

        private void N6_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(6);
        }

        private void N7_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(7);
        }

        private void N8_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(8);
        }

        private void N9_Button_OnClick(object sender, RoutedEventArgs e)
        {
            AddNumberToExpression(9);
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
            AddValueToExpression( Math.PI );
        }

        private void Euler_Button_OnClick(object sender , RoutedEventArgs e)
        {
            AddValueToExpression(Math.E);
        }

        private void Clear_Button_OnClick(object sender, RoutedEventArgs e)
        {
            LogMessage("Clear button clicked");
        }

        private void ClearAll_Button_OnClick(object sender, RoutedEventArgs e)
        {
            LogMessage("Clear All button clicked");
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
    }
}
