# ComplexNumbers

using System;
using System.Collections.Generic;
using System.Text;
using indice.Edi.Serialization;

namespace Nop.Core.Domain.EdiStandards
{
    public class X12_855_OrderConfirmation
    {

        #region ISA and IEA
        [EdiValue("9(2)", Path = "ISA/0", Description = "ISA01 - Authorization Information Qualifier")]
        public int AuthorizationInformationQualifier { get; set; }

        [EdiValue("X(10)", Path = "ISA/1", Description = "ISA02 - Authorization Information")]
        public string AuthorizationInformation { get; set; }

        [EdiValue("9(2)", Path = "ISA/2", Description = "ISA03 - Security Information Qualifier")]
        public string Security_Information_Qualifier { get; set; }

        [EdiValue("X(10)", Path = "ISA/3", Description = "ISA04 - Security Information")]
        public string Security_Information { get; set; }

        [EdiValue("9(2)", Path = "ISA/4", Description = "ISA05 - Interchange ID Qualifier")]
        public string ID_Qualifier { get; set; }

        [EdiValue("X(15)", Path = "ISA/5", Description = "ISA06 - Interchange Sender ID")]
        public string Sender_ID { get; set; }

        [EdiValue("9(2)", Path = "ISA/6", Description = "ISA07 - Interchange ID Qualifier")]
        public string ID_Qualifier2 { get; set; }

        [EdiValue("X(15)", Path = "ISA/7", Description = "ISA08 - Interchange Receiver ID")]
        public string Receiver_ID { get; set; }

        [EdiValue("9(6)", Path = "ISA/8", Format = "yyMMdd", Description = "I09 - Interchange Date")]
        [EdiValue("9(4)", Path = "ISA/9", Format = "HHmm", Description = "I10 - Interchange Time")]
        public DateTime Date { get; set; }

        [EdiValue("X(1)", Path = "ISA/10", Description = "ISA11 - Interchange Control Standards ID")]
        public string Control_Standards_ID { get; set; }

        [EdiValue("9(5)", Path = "ISA/11", Description = "ISA12 - Interchange Control Version Num")]
        public int ControlVersion { get; set; }

        [EdiValue("9(9)", Path = "ISA/12", Description = "ISA13 - Interchange Control Number")]
        public int ControlNumber { get; set; }

        [EdiValue("9(1)", Path = "ISA/13", Description = "ISA14 - Acknowledgement Requested")]
        public bool? AcknowledgementRequested { get; set; }

        [EdiValue("X(1)", Path = "ISA/14", Description = "ISA15 - Usage Indicator")]
        public string Usage_Indicator { get; set; }

        [EdiValue("X(1)", Path = "ISA/15", Description = "ISA16 - Component Element Separator")]
        public char? Component_Element_Separator { get; set; }

        [EdiValue("9(1)", Path = "IEA/0", Description = "IEA01 - Num of Included Functional Grps")]
        public int GroupsCount { get; set; }

        [EdiValue("9(9)", Path = "IEA/1", Description = "IEA02 - Interchange Control Number")]
        public int TrailerControlNumber { get; set; }

        #endregion

        public List<FunctionalGroup> Groups { get; set; }

        [EdiGroup]
        public class FunctionalGroup
        {

            [EdiValue("X(2)", Path = "GS/0", Description = "GS01 - Functional Identifier Code")]
            public string FunctionalIdentifierCode { get; set; }

            [EdiValue("X(15)", Path = "GS/1", Description = "GS02 - Application Sender's Code")]
            public string ApplicationSenderCode { get; set; }

            [EdiValue("X(15)", Path = "GS/2", Description = "GS03 - Application Receiver's Code")]
            public string ApplicationReceiverCode { get; set; }

            [EdiValue("9(8)", Path = "GS/3", Format = "yyyyMMdd", Description = "GS04 - Date")]
            [EdiValue("9(4)", Path = "GS/4", Format = "HHmm", Description = "GS05 - Time")]
            public DateTime Date { get; set; }

            [EdiValue("9(9)", Path = "GS/5", Format = "HHmm", Description = "GS06 - Group Control Number")]
            public int GroupControlNumber { get; set; }

            [EdiValue("X(2)", Path = "GS/6", Format = "HHmm", Description = "GS07 Responsible Agency Code")]
            public string AgencyCode { get; set; }

            [EdiValue("X(2)", Path = "GS/7", Format = "HHmm", Description = "GS08 Version / Release / Industry Identifier Code")]
            public string Version { get; set; }

            public List<Order> Orders { get; set; }


            [EdiValue("9(1)", Path = "GE/0", Description = "97 Number of Transaction Sets Included")]
            public int TransactionsCount { get; set; }

            [EdiValue("9(9)", Path = "GE/1", Description = "28 Group Control Number")]
            public int GroupTrailerControlNumber { get; set; }
        }

        [EdiMessage]
        public class Order
        {
            #region Header Trailer

            [EdiValue("X(3)", Path = "ST/0", Description = "ST01 - Transaction set ID code")]
            public string TransactionSetCode { get; set; }

            [EdiValue("X(9)", Path = "ST/1", Description = "ST02 - Transaction set control number")]
            public string TransactionSetControlNumber { get; set; }

            [EdiValue(Path = "SE/0", Description = "SE01 - Number of included segments")]
            public int SegmentsCouts { get; set; }

            [EdiValue("X(9)", Path = "SE/1", Description = "SE02 - Transaction set control number (same as ST02)")]
            public string TrailerTransactionSetControlNumber { get; set; }
            #endregion

            //[EdiValue("X(2)", Path = "BEG/0", Description = "BEG01 - Trans. Set Purpose Code")]
            //public string TransSetPurposeCode { get; set; }

            //[EdiValue("X(2)", Path = "BEG/1", Description = "BEG02 - Purchase Order Type Code")]
            //public string PurchaseOrderTypeCode { get; set; }

            //[EdiValue(Path = "BEG/2", Description = "BEG03 - Purchase Order Number")]
            //public string PurchaseOrderNumber { get; set; }

            //[EdiValue("9(8)", Path = "BEG/4", Format = "yyyyMMdd", Description = "BEG05 - Purchase Order Date")]
            //public string PurchaseOrderDate { get; set; }

            //[EdiValue(Path = "CUR/0", Description = "CUR01 - Entity Identifier Code")]
            //public string EntityIdentifierCode { get; set; }

            //[EdiValue("X(3)", Path = "CUR/1", Description = "CUR02 - Currency Code")]
            //public string CurrencyCode { get; set; }

            //[EdiValue(Path = "REF/0", Description = "REF01 - Reference Identification Qualifier IA – Vendor Number assigned by Carhartt")]
            //public string ReferenceIdentificationQualifier { get; set; }

            //[EdiValue(Path = "REF/1", Description = "REF02 - Reference Identification")]
            //public string ReferenceIdentification { get; set; }

            //[EdiValue(Path = "FOB/4", Description = "FOB05 - Transportation Terms code")]
            //public string TransportationTermscode { get; set; }

            //[EdiValue(Path = "FOB/5", Description = "FOB06 - Code identifying type of location KL – Port of loading")]
            //public string LocationQualifier { get; set; }

            //[EdiValue("X(2)", Path = "ITD/0", Description = "ITD01 - Terms Type Code")]
            //public string TermsTypeCode { get; set; }

            //[EdiValue(Path = "ITD/1", Description = "ITD02 - Terms Basis Date Code")]
            //public string TermsBasisDateCode { get; set; }

            //[EdiValue(Path = "ITD/6", Description = "ITD07 - Terms Net Days")]
            //public string TermsNetDays { get; set; }

            //[EdiValue(Path = "TD5/3", Description = "TD504 - Transportation Method/Type Code")]
            //public string TransportationMethod { get; set; }

            //[EdiValue(Path = "MSG/0", Description = "MSG01 - Message Text")]
            //public string OrderHeaderMessageText { get; set; }

            public List<Address> Addresses { get; set; }

            public List<OrderDetail> Items { get; set; }

            [EdiValue(Path = "CTT/0", Description = "CTT01 - Transaction Totals")]
            public int NoOfLineItems { get; set; }

            [EdiValue(Path = "MSG/0", Description = "MSG01 - Message Text")]
            public string OrderHeaderMessageText { get; set; }


            //[EdiValue(Path = "AMT/1", Description = "AMT02 - Total amount of the Purchase Order")]
            //public string TotalTransactionAmount { get; set; }

        }

        [EdiSegment, EdiSegmentGroup("PO1", SequenceEnd = "CTT")]
        public class OrderDetail
        {
            [EdiValue(Path = "PO1/0", Description = "PO101 - Order Line Number")]
            public string OrderLineNumber { get; set; }

            [EdiValue(Path = "PO1/1", Description = "PO102 - Quantity Ordered")]
            public decimal QuantityOrdered { get; set; }

            [EdiValue(Path = "PO1/2", Description = "PO103 - Unit Of Measurement")]
            public string UnitOfMeasurement { get; set; }

            [EdiValue(Path = "PO1/3", Description = "PO104 - Unit Price")]
            public decimal UnitPrice { get; set; }

            [EdiValue(Path = "PO1/5", Description = "PO106 - Product Service/ID Qualifier")]
            public string ProductQualifier { get; set; }

            [EdiValue(Path = "PO1/7", Description = "PO108 - Product Service/ID ")]
            public string ProductServiceQualifier { get; set; } = "IN";

            [EdiValue(Path = "PO1/8", Description = "PO109 - Buyer’s Part #.")]
            public string BuyersPartno { get; set; }

            [EdiValue(Path = "PO1/10", Description = "PO111 - Vendor’s Part #.")]
            public string VendorsPartno { get; set; }

            [EdiValue(Path = "PID/4", Description = "PID05 - Product Description")]
            public string ProductDescription { get; set; }

            //[EdiValue(Path = "MEA/2", Description = "MEA03 - Measurement Value")]
            //public decimal MeasurementValue { get; set; }

            [EdiCondition("018", Path = "DTM/0/0")]
            public DTM AvailableFromDate { get; set; }

            [EdiCondition("067", Path = "DTM/0/0")]
            public DTM ArrivalDate { get; set; }

            [EdiCondition("002", Path = "DTM/0/0")]
            public DTM DeliveryRequestedDate { get; set; }

            [EdiCondition("038", Path = "DTM/0/0")]
            public DTM ShipNoLaterDate { get; set; }

            [EdiCondition("038", Path = "DTM/0/0")]
            public ACK Acknowledgment { get; set; }
            //[EdiValue(Path = "TC2/0", Description = "TC201 - Measurement Value")]
            //public string TC201 { get; set; }
            //public List<MSG> MSG { get; set; }

        }

        [EdiSegment, EdiSegmentGroup("N1", SequenceEnd = "PO1")]
        public class Address
        {

            [EdiValue(Path = "N1/0", Description = "N101 - Address Code")]
            public string AddressCode { get; set; }

            [EdiValue(Path = "N1/1", Description = "N102 - Address Name")]
            public string AddressName { get; set; }

            //[EdiValue(Path = "N3/0", Description = "N301 - Address Information")]
            //public string AddressInformation { get; set; }

            //[EdiValue(Path = "N4/0", Description = "N401 - City Name")]
            //public string CityName { get; set; }

            //[EdiValue(Path = "N4/3", Description = "N404 - Country Code")]
            //public string CountryCode { get; set; }

        }

        [EdiSegment, EdiPath("DTM")]
        public class DTM
        {

            [EdiValue(Path = "DTM/0", Description = "DTM01 - Date/Time Qualifier")]
            public string DateTimeQualifier { get; set; }

            [EdiValue("9(8)", Path = "DTM/1", Format = "yyyyMMdd", Description = "DTM02 - Date format =CCYYMMDD")]
            public DateTime Date { get; set; }
        }

        public class ACK
        {
            [EdiValue(Path = "ACK/0", Description = "ACK01 - Line Item Status Code")]
            public string ListItemStatusCode { get; set; } = "IA";
            [EdiValue(Path = "ACK/1", Description = "ACK02 - Quantity")]
            public int Quantity { get; set; }
            [EdiValue(Path = "ACK/2", Description = "ACK03 - Unit or Basis of Measurement")]
            public string UnitOfMeasurementCode { get; set; }
            [EdiValue(Path = "ACK/3", Description = "ACK04 - DateTime Qualifier")]
            public string DateTimeQualifier { get; set; }
            [EdiValue(Path = "ACK/4", Description = "ACK05 - Date")]
            public DateTime Date { get; set; }
            [EdiValue(Path = "ACK/5", Description = "ACK06 - Request Refereence Number")]
            public string RequestRefNumber { get; set; }
            [EdiValue(Path = "ACK/6", Description = "ACK07 - Transaction Set Purpose Code")]
            public string ProductIdQualification { get; set; }
            [EdiValue(Path = "ACK/7", Description = "ACK08 - Product/Service ID")]
            public string ProductId { get; set; }
            [EdiValue(Path = "ACK/8", Description = "ACK09 - Product/Service ID Qualifier")]
            public string ProductTypeQualifier { get; set; } = "IN";
            [EdiValue(Path = "ACK/9", Description = "ACK10 - Product/Service ID")]
            public string CustomerProductNumber { get; set; }
        }

        public class BAK
        {
            [EdiValue(Path = "BAK/0", Description = "BAK01 - Transaction Set Purpose Code")]
            public string TransactionSetPurpose { get; set; }
            [EdiValue(Path = "BAK/1", Description = "BAK02 - Acknowledgement Type")]
            public string AckType { get; set; }
            [EdiValue(Path = "BAK/2", Description = "BAK03 - Purchase Order Number")]
            public string PurchaseOrderNo { get; set; }
            [EdiValue(Path = "BAK/3", Format = "yyMMdd", Description = "BAK04 - Date")]
            public DateTime  Date1 { get; set; }
            [EdiValue(Path = "BAK/4", Description = "BAK05 - Release Number")]
            public string ReleaseNumber { get; set; }
            [EdiValue(Path = "BAK/5", Description = "BAK06 - Request Reference Number")]
            public string RequestRefNumber { get; set; }
            [EdiValue(Path = "BAK/6", Description = "BAK07 - Contract Number")]
            public string ContractNumber { get; set; }
            [EdiValue(Path = "BAK/7", Description = "BAK08 - Reference Identification")]
            public string ReferenceIdentification { get; set; }
            [EdiValue(Path = "BAK/8", Format = "yyMMdd", Description = "BAK09 - Reference Identification")]
            public DateTime Date2 { get; set; }
        }

        //[EdiSegment, EdiPath("CTT")]
        //public class LineItemsCount
        //{
        //    public int NoOfLineItems { get; set; }
        //}

        //[EdiElement, EdiPath("MSG/0")]
        //public class MSG
        //{

        //    [EdiValue(Path = "MSG/0", Description = "MSG01 - Message Text")]
        //    public string MessageText { get; set; }
        //}

        #region Edi Enumerations
        #endregion
    }
}



        public string GetOrderConfirmation(Order order)
        {
            #region Addressing Section

            X12_855_OrderConfirmation.Address PrepareAddress(string addressCode, Address pAddress)
            {
                List<string> addressSegments = new List<string>();
                //
                string address1 = pAddress.Address1;
                addressSegments.Add(address1);
                //
                string zip = string.Empty;
                if (!string.IsNullOrEmpty(pAddress.ZipPostalCode))
                {
                    zip = pAddress.ZipPostalCode;
                    addressSegments.Add(zip);
                }
                //
                string city = string.Empty;
                if (!string.IsNullOrEmpty(pAddress.City))
                {
                    city = pAddress.City;
                    addressSegments.Add(city);
                }
                //
                string state = pAddress.StateProvince?.Name;
                if (!string.IsNullOrEmpty(state))
                {
                    addressSegments.Add(state);
                }
                //
                string country = pAddress.Country?.Name;
                if (!string.IsNullOrEmpty(country))
                {
                    addressSegments.Add(country);
                }
                //
                string address = string.Join(", ", addressSegments);

                X12_855_OrderConfirmation.Address sfAddress = new X12_855_OrderConfirmation.Address();
                sfAddress.AddressCode = addressCode;
                sfAddress.AddressName = address;
                //
                return sfAddress;
            }

            X12_855_OrderConfirmation.Order PrepareOrder()
            {
                X12_855_OrderConfirmation.Order ediOrder = new X12_855_OrderConfirmation.Order();
                // addresses
                X12_855_OrderConfirmation.Address stAddress = PrepareAddress("ST", order.ShippingAddress);
                ediOrder.NoOfLineItems = order.OrderItems.Count;
                ediOrder.Addresses = new List<X12_855_OrderConfirmation.Address>();
                ediOrder.Addresses.Add(stAddress);
                //
                int counter = 1;
                //
                ediOrder.Items = new List<X12_855_OrderConfirmation.OrderDetail>();
                foreach (var orderItem in order.OrderItems)
                {
                    ediOrder.Items.Add(new X12_855_OrderConfirmation.OrderDetail()
                    {
                        OrderLineNumber = counter.ToString().PadLeft(6, '0'),
                        QuantityOrdered = orderItem.Quantity,
                        UnitOfMeasurement = string.Empty,
                        UnitPrice = orderItem.UnitPriceExclTax,
                        ProductQualifier = "VC",
                        ProductServiceQualifier = "IN",
                        BuyersPartno = orderItem.ProductNumber,
                        ProductDescription = orderItem.Name,
                        DeliveryRequestedDate = new X12_855_OrderConfirmation.DTM()
                        {
                            DateTimeQualifier = "067",
                            Date = order.ShippingDate
                        }
                    });
                    //
                    counter += 1;
                }
                //
                return ediOrder;
            }

            #endregion

            string output = null;
            try
            {
                //
                var grammar = EdiGrammar.NewX12();
                var interchange = new X12_855_OrderConfirmation();
                interchange.AuthorizationInformationQualifier = 00;
                interchange.AuthorizationInformation = "          ";
                interchange.Security_Information_Qualifier = "00";
                interchange.Security_Information = "          ";
                interchange.ID_Qualifier = "ZZ";
                interchange.Sender_ID = "BerryDirect";
                interchange.ID_Qualifier2 = "ZZ";
                interchange.Receiver_ID = "SYSCOXXX";
                interchange.Control_Standards_ID = "U";
                interchange.ControlVersion = 00401;
                // 000159202 9 digit
                interchange.ControlNumber = 000159202;
                interchange.AcknowledgementRequested = false;
                // T for test data, P for production data
                interchange.Usage_Indicator = "T";
                //
                var functionalGroup = new Nop.Core.Domain.EdiStandards.X12_855_OrderConfirmation.FunctionalGroup();
                functionalGroup.FunctionalIdentifierCode = "PO";
                functionalGroup.ApplicationSenderCode = "BerryDirect";
                functionalGroup.ApplicationReceiverCode = "SYSCOXXX";
                functionalGroup.GroupControlNumber = 32027;
                functionalGroup.AgencyCode = "X";
                functionalGroup.Version = "00401";
                functionalGroup.Orders = new List<X12_855_OrderConfirmation.Order>();
                //
                var ediOrder = PrepareOrder();
                functionalGroup.Orders.Add(ediOrder);
                //
                interchange.Groups.Add(functionalGroup);
                //
                using (var writer = new StringWriter())
                {
                    new EdiSerializer().Serialize(writer, grammar, interchange);
                    output = writer.ToString();
                }
            }
            catch { }
            return output;
        }
