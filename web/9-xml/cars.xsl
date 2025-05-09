<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <!-- Output HTML -->
  <xsl:output method="html" indent="yes"/>

  <!-- Match root -->
  <xsl:template match="/">

    <html>
      <head>
        <title>Car Showroom</title>
      </head>
      <body>
        <h2>Available Cars</h2>
        <table border="1" cellpadding="8" cellspacing="0">
          <tr bgcolor="#dddddd">
            <th>Model</th>
            <th>Price</th>
            <th>Color</th>
          </tr>

          <!-- Loop through car elements -->
          <xsl:for-each select="car_showroom/car">
            <tr>
              <td><xsl:value-of select="model"/></td>
              <td><xsl:value-of select="price"/></td>
              <td><xsl:value-of select="color"/></td>
            </tr>
          </xsl:for-each>

        </table>
      </body>
    </html>

  </xsl:template>
</xsl:stylesheet>
