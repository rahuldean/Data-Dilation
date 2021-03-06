﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Xml.Linq;

namespace SDMGUISL
{

	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			this.InitializeComponent();

    
        }

        private void WindowLoaded(object sender, RoutedEventArgs e)
        {
            #region Initialize GMAP Flash
            string myAPIKey = "ABQIAAAAXUIntRdhM7bnKfEb2SX9iBRRea433IgTedYfpjirThGznaRcnxReD4gO9PTHyyd8f15JMWS8PRAnxA";
            AxShockwaveFlashObjects.AxShockwaveFlash axFlash = wfh.Child as AxShockwaveFlashObjects.AxShockwaveFlash;
            axFlash.FlashVars = myAPIKey;
            axFlash.Movie = System.Windows.Forms.Application.StartupPath + "\\GoogleMaps.swf";

            axFlash.FlashCall += new AxShockwaveFlashObjects._IShockwaveFlashEvents_FlashCallEventHandler(axFlash_FlashCall);
            #endregion
        }

        #region GMAP Flash Methods
        void axFlash_FlashCall(object sender, AxShockwaveFlashObjects._IShockwaveFlashEvents_FlashCallEvent e)
        {
            XDocument call = XDocument.Parse(e.request);

            var q = from c in call.Elements("invoke")
                    select new
                    {
                        Name = c.Attribute("name").Value,
                        Arguments = c.Element("arguments").Descendants()
                    };
            foreach (var i in q)
            {
                if (i.Name == "setPosition")
                {
                    lat.Text = i.Arguments.ElementAt(0).Value;
                    lng.Text = i.Arguments.ElementAt(1).Value;
                }
            }

        }

        private void TextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
                Search_Click(sender, null);
        }

        private void Search_Click(object sender, RoutedEventArgs e)
        {
            AxShockwaveFlashObjects.AxShockwaveFlash axFlash = wfh.Child as AxShockwaveFlashObjects.AxShockwaveFlash;

            XElement call = new XElement("invoke",
                    new XAttribute("name", "Search"),
                    new XAttribute("returntype", "xml"),
                    new XElement("arguments",
                        new XElement("string", address.Text)
                    )
                );
            axFlash.CallFunction(call.ToString(SaveOptions.DisableFormatting));
        }
        #endregion
    }
}