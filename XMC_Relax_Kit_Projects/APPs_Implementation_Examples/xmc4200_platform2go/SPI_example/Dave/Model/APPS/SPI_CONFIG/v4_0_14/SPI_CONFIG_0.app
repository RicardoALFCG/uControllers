<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="SPI_CONFIG" URI="http://resources/4.0.14/app/SPI_CONFIG/0" description="Configures the USIC peripheral to work for the SPI protocol." mode="NOTSHARABLE" version="4.0.14" minDaveVersion="4.1.2" instanceLabel="SPI_CONFIG_0" appLabel="">
  <properties provideInit="true"/>
  <virtualSignals name="miso" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx0ins" hwSignal="dx0ins" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="dx1ins" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx1ins" hwSignal="dx1ins" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="dx1ins_out" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx1ins_sys_out" hwSignal="dx1ins" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="dx2ins" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx2ins" hwSignal="dx2ins" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="dx2ins_out" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx2ins_sys_out" hwSignal="dx2ins" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="miso[1]" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx3ins" hwSignal="dx3ins" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="miso[2]" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx4ins" hwSignal="dx4ins" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="miso[3]" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx5ins" hwSignal="dx5ins" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="mosi" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dout0" hwSignal="dout0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mosi/miso[1]" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dout1" hwSignal="dout1" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="mosi/miso[2]" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dout2" hwSignal="dout2" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="mosi/miso[3]" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dout3" hwSignal="dout3" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="sclkout" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_sclkout" hwSignal="sclkout" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mclkout" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_mclkout" hwSignal="mclkout" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="selo0" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_0" hwResource="//@hwResources.0" visible="true" solverVariableName="sv0" solverVariableValue=""/>
  <virtualSignals name="selo1" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_1" hwResource="//@hwResources.0" required="false" visible="true" solverVariableName="sv1" solverVariableValue=""/>
  <virtualSignals name="selo2" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_2" hwResource="//@hwResources.0" required="false" visible="true" solverVariableName="sv2" solverVariableValue=""/>
  <virtualSignals name="selo3" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_3" hwResource="//@hwResources.0" required="false" visible="true" solverVariableName="sv3" solverVariableValue=""/>
  <virtualSignals name="selo4" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_4" hwResource="//@hwResources.0" required="false" visible="true" solverVariableName="sv4" solverVariableValue=""/>
  <virtualSignals name="selo5" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_5" hwResource="//@hwResources.0" required="false" visible="true" solverVariableName="sv5" solverVariableValue=""/>
  <virtualSignals name="selo6" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_6" hwResource="//@hwResources.0" required="false" visible="true" solverVariableName="sv6" solverVariableValue=""/>
  <virtualSignals name="selo7" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_selo_7" hwResource="//@hwResources.0" required="false" visible="true" solverVariableName="sv7" solverVariableValue=""/>
  <virtualSignals name="transmit_buffer_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_standard_tx_event" hwSignal="transmit_buffer_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="standard_receive_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_standard_rx_event" hwSignal="standard_receive_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="transmit_shift_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_tx_shift_event" hwSignal="transmit_shift_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="receive_start_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_rx_start_event" hwSignal="receive_start_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="alternate_receive_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_alt_rx_event" hwSignal="alternate_receive_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="protocol_specific_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_proto_specfic_event" hwSignal="protocol_specific_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="fifo_standard_transmit_buffer_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_fifo_tx_event" hwSignal="standard_transmit_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="fifo_transmit_buffer_error_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_fifo_tx_err_event" hwSignal="transmit_buffer_error_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="fifo_standard_receive_buffer_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_fifo_rx_event" hwSignal="standard_receive_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="fifo_receive_buffer_error_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_fifo_rx_err_event" hwSignal="receive_buffer_error_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="fifo_alternate_receive_buffer_event" URI="http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_fifo_alt_rx_event" hwSignal="alternate_receive_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <requiredApps URI="http://resources/4.0.14/app/SPI_CONFIG/0/ra_clock" requiredAppName="CLOCK_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK_XMC4/v4_0_24/CLOCK_XMC4_0.app#/"/>
  </requiredApps>
  <hwResources name="Channel" URI="http://resources/4.0.14/app/SPI_CONFIG/0/hwres_usic_channel" resourceGroupUri="peripheral/usic/*/channel/*" mResGrpUri="peripheral/usic/*/channel/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/USIC0/USIC0_0.dd#//@provided.43"/>
  </hwResources>
  <connections URI="http://resources/4.0.14/app/SPI_CONFIG/0/http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dout0/http://resources/4.0.14/app/SPI_CONFIG/0/vs_spi_dx0ins" systemDefined="true" sourceSignal="mosi" targetSignal="miso" required="false" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.0"/>
</ResourceModel:App>
