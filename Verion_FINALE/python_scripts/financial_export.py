#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Excel Export for Financial Balance Sheet
Generates professional financial reports from transaction data using xlsxwriter
"""

import sys
import json
from datetime import datetime
import xlsxwriter


def create_bilan_financier(transactions, output_path):
    """
    Create a professional Financial Balance Sheet Excel file with proper formatting using xlsxwriter
    
    Args:
        transactions: List of transaction dictionaries
        output_path: Path where the Excel file will be saved
    """
    try:
        # Create a new Excel file
        workbook = xlsxwriter.Workbook(output_path)
        worksheet = workbook.add_worksheet('Financial Balance')
        
        # Define formats
        header_format = workbook.add_format({
            'bold': True,
            'font_size': 16,
            'font_color': 'white',
            'bg_color': '#1F4E78',
            'align': 'center',
            'valign': 'vcenter',
            'border': 1
        })
        
        section_format = workbook.add_format({
            'bold': True,
            'font_size': 12,
            'font_color': 'white',
            'bg_color': '#4472C4',
            'align': 'center',
            'valign': 'vcenter',
            'border': 1
        })
        
        label_format = workbook.add_format({
            'bold': True,
            'font_size': 11,
            'align': 'left',
            'valign': 'vcenter',
            'border': 1
        })
        
        label_right_format = workbook.add_format({
            'bold': True,
            'font_size': 11,
            'align': 'right',
            'valign': 'vcenter',
            'border': 1
        })
        
        total_format = workbook.add_format({
            'bold': True,
            'font_size': 11,
            'bg_color': '#E7E6E6',
            'align': 'right',
            'valign': 'vcenter',
            'num_format': '#,##0.00 "DT"',
            'border': 1
        })
        
        currency_format = workbook.add_format({
            'font_size': 11,
            'align': 'right',
            'valign': 'vcenter',
            'num_format': '#,##0.00 "DT"',
            'border': 1
        })
        
        positive_format = workbook.add_format({
            'bold': True,
            'font_size': 11,
            'bg_color': '#C6EFCE',
            'font_color': '#006100',
            'align': 'right',
            'valign': 'vcenter',
            'num_format': '#,##0.00 "DT"',
            'border': 1
        })
        
        negative_format = workbook.add_format({
            'bold': True,
            'font_size': 11,
            'bg_color': '#FFC7CE',
            'font_color': '#9C0006',
            'align': 'right',
            'valign': 'vcenter',
            'num_format': '#,##0.00 "DT"',
            'border': 1
        })
        
        center_format = workbook.add_format({
            'font_size': 11,
            'align': 'center',
            'valign': 'vcenter',
            'border': 1
        })
        
        date_format = workbook.add_format({
            'font_size': 10,
            'italic': True,
            'align': 'center',
            'valign': 'vcenter'
        })
        
        table_header_format = workbook.add_format({
            'bold': True,
            'font_size': 11,
            'bg_color': '#E7E6E6',
            'align': 'center',
            'valign': 'vcenter',
            'border': 1
        })
        
        # Set column widths
        worksheet.set_column('A:A', 5)
        worksheet.set_column('B:B', 35)
        worksheet.set_column('C:C', 20)
        worksheet.set_column('D:D', 20)
        worksheet.set_column('E:E', 20)
        worksheet.set_column('F:F', 15)
        
        current_row = 0
        
        # ===== HEADER =====
        worksheet.merge_range(current_row, 0, current_row, 4, 
                             'FINANCIAL BALANCE SHEET - VOLTSHOP', header_format)
        current_row += 1
        
        worksheet.merge_range(current_row, 0, current_row, 4,
                             f"Generated on {datetime.now().strftime('%m/%d/%Y at %H:%M')}", 
                             date_format)
        current_row += 2
        
        # Calculate financial metrics
        total_amount = sum(float(t.get('AMOUNT', 0)) for t in transactions)
        
        # Status mapping - handle both English and the actual status values
        completed_trans = []
        pending_trans = []
        failed_trans = []
        
        for t in transactions:
            status = t.get('STATUS', '').strip().lower()
            if status in ['payed', 'completed', 'success']:
                completed_trans.append(t)
            elif status in ['in progress', 'pending']:
                pending_trans.append(t)
            elif status in ['canceled', 'failed', 'cancelled']:
                failed_trans.append(t)
            else:
                # Default to pending if unknown
                pending_trans.append(t)
        
        completed_amount = sum(float(t.get('AMOUNT', 0)) for t in completed_trans)
        pending_amount = sum(float(t.get('AMOUNT', 0)) for t in pending_trans)
        failed_amount = sum(float(t.get('AMOUNT', 0)) for t in failed_trans)
        
        # Payment methods breakdown
        payment_methods = {}
        for t in transactions:
            method = t.get('PAY_METHOD', 'Not Specified')
            amount = float(t.get('AMOUNT', 0))
            payment_methods[method] = payment_methods.get(method, 0) + amount
        
        # ===== ASSETS =====
        worksheet.merge_range(current_row, 1, current_row, 4, 'ASSETS', section_format)
        current_row += 1
        
        worksheet.write(current_row, 1, 'Current Assets', label_format)
        current_row += 1
        
        worksheet.write(current_row, 1, '  Cash (Completed Transactions)', label_format)
        worksheet.write(current_row, 2, completed_amount, currency_format)
        current_row += 1
        
        worksheet.write(current_row, 1, '  Accounts Receivable (Pending Transactions)', label_format)
        worksheet.write(current_row, 2, pending_amount, currency_format)
        current_row += 1
        
        total_assets = completed_amount + pending_amount
        worksheet.write(current_row, 1, 'Total Assets', label_right_format)
        worksheet.write(current_row, 2, total_assets, total_format)
        current_row += 2
        
        # ===== LIABILITIES =====
        worksheet.merge_range(current_row, 1, current_row, 4, 'LIABILITIES', section_format)
        current_row += 1
        
        worksheet.write(current_row, 1, 'Current Liabilities', label_format)
        current_row += 1
        
        worksheet.write(current_row, 1, '  Debts (Failed/Canceled Transactions)', label_format)
        worksheet.write(current_row, 2, failed_amount, currency_format)
        current_row += 1
        
        total_liabilities = failed_amount
        worksheet.write(current_row, 1, 'Total Liabilities', label_right_format)
        worksheet.write(current_row, 2, total_liabilities, total_format)
        current_row += 2
        
        # ===== EQUITY =====
        worksheet.merge_range(current_row, 1, current_row, 4, 'EQUITY', section_format)
        current_row += 1
        
        equity = total_assets - total_liabilities
        worksheet.write(current_row, 1, "Owner's Equity", label_right_format)
        worksheet.write(current_row, 2, equity, total_format)
        current_row += 2
        
        # ===== FINANCIAL SUMMARY =====
        worksheet.merge_range(current_row, 1, current_row, 4, 'FINANCIAL SUMMARY', section_format)
        current_row += 1
        
        worksheet.write(current_row, 1, 'Total Number of Transactions', label_format)
        worksheet.write(current_row, 2, len(transactions), center_format)
        current_row += 1
        
        worksheet.write(current_row, 1, 'Total Amount', label_format)
        worksheet.write(current_row, 2, total_amount, currency_format)
        current_row += 1
        
        worksheet.write(current_row, 1, 'Completed Transactions', label_format)
        worksheet.write(current_row, 2, len(completed_trans), center_format)
        current_row += 1
        
        worksheet.write(current_row, 1, 'Pending Transactions', label_format)
        worksheet.write(current_row, 2, len(pending_trans), center_format)
        current_row += 1
        
        worksheet.write(current_row, 1, 'Failed/Canceled Transactions', label_format)
        worksheet.write(current_row, 2, len(failed_trans), center_format)
        current_row += 1
        
        net_income = completed_amount - failed_amount
        worksheet.write(current_row, 1, 'Net Income', label_right_format)
        if net_income >= 0:
            worksheet.write(current_row, 2, net_income, positive_format)
        else:
            worksheet.write(current_row, 2, net_income, negative_format)
        current_row += 2
        
        # ===== BREAKDOWN BY PAYMENT METHOD =====
        worksheet.merge_range(current_row, 1, current_row, 4, 'BREAKDOWN BY PAYMENT METHOD', section_format)
        current_row += 1
        
        for method, amount in sorted(payment_methods.items()):
            worksheet.write(current_row, 1, f'  {method}', label_format)
            worksheet.write(current_row, 2, amount, currency_format)
            current_row += 1
        
        current_row += 1
        
        # ===== TRANSACTION DETAILS =====
        worksheet.merge_range(current_row, 0, current_row, 5, 'TRANSACTION DETAILS', section_format)
        current_row += 1
        
        # Table headers
        headers = ['Trans ID', 'Ref ID', 'Amount (DT)', 'Payment Method', 'Date', 'Status']
        for col, header in enumerate(headers):
            worksheet.write(current_row, col, header, table_header_format)
        current_row += 1
        
        # Transaction rows
        for trans in transactions:
            worksheet.write(current_row, 0, trans.get('IDT', ''), center_format)
            worksheet.write(current_row, 1, trans.get('ID', ''), center_format)
            worksheet.write(current_row, 2, float(trans.get('AMOUNT', 0)), currency_format)
            worksheet.write(current_row, 3, trans.get('PAY_METHOD', 'N/A'), center_format)
            worksheet.write(current_row, 4, trans.get('DATE_TRANS', 'N/A'), center_format)
            worksheet.write(current_row, 5, trans.get('STATUS', 'N/A'), center_format)
            current_row += 1
        
        # Close the workbook
        workbook.close()
        return True
        
    except Exception as e:
        print(f"ERROR in create_bilan_financier: {str(e)}", file=sys.stderr)
        import traceback
        traceback.print_exc(file=sys.stderr)
        return False


def main():
    """
    Main entry point for the script
    Reads JSON from stdin and generates Excel file
    """
    try:
        # Get output path from command line argument
        if len(sys.argv) < 2:
            print("ERROR: Output path not provided", file=sys.stderr)
            sys.exit(1)
        
        output_path = sys.argv[1]
        
        # Read JSON from stdin
        input_data = sys.stdin.read()
        transactions = json.loads(input_data)
        
        if not isinstance(transactions, list):
            print("ERROR: Input data must be a list of transactions", file=sys.stderr)
            sys.exit(1)
        
        # Create the Excel file
        success = create_bilan_financier(transactions, output_path)
        
        if success:
            print(f"SUCCESS: Excel file created: {output_path}")
            sys.exit(0)
        else:
            print("ERROR: Failed to create Excel file", file=sys.stderr)
            sys.exit(1)
            
    except json.JSONDecodeError as e:
        print(f"ERROR: Invalid JSON input: {e}", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"ERROR: {str(e)}", file=sys.stderr)
        import traceback
        traceback.print_exc(file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
