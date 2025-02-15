# The GENIE Event Generator

The GENIE Generator product is an advanced physics simulation used by nearly all modern neutrino experiments and 
it plays a key role in the exploitation of neutrino data. This product implements a modern software framework for 
MC event generators and includes state-of-the-art physics modules for neutrino or charged-lepton interactions 
with nucleons or nuclei, and for the simulation of nucleon decay, n-bar oscillation and boosted dark matter. 
It captures the latest results of the GENIE global analysis of neutrino scattering data and includes several tunes 
that were produced using the proprietary Comparisons and Tuning products.
The GENIE physics model is universal and comprehensive:  It handles all neutrinos and targets, and all processes 
relevant from MeV to PeV energy scales. The Generator includes several tools (flux drivers, detector geometry 
navigation drivers, specialized event generation apps, event reweighting engines) to simulate complex experimental 
setups in full detail and to support generator-related analysis tasks. 

For more information, visit http://www.genie-mc.org

<pre>
                                                   .oooooo.    oooooooooooo ooooo      ooo ooooo oooooooooooo  
                                                  d8P'  `Y8b   `888'     `8 `888b.     `8' `888' `888'     `8  
                                                 888            888          8 `88b.    8   888   888           
                        Ndyooym          dN      888            888oooo8     8   `88b.  8   888   888oooo8     
                     Nds//+sdmoy       d+m       888     ooooo  888    "     8     `88b.8   888   888    "      
                   Nh+//ohN  m+s      N//syyN    `88.    .88'   888       o  8       `888   888   888       o  
                 Ny+//od   Nh+oN       o///+      `Y8bood8P'   o888ooooood8 o8o        `8  o888o o888ooooood8  
               Nh+//om   Nh+/yN       o///s                                                                    
              d+//+d   my+/smmyhN    m///h                                         MONTE CARLO EVENT GENERATOR    
            Ns///yN NdyoshNNs///d   h////yN                                                                    
           mo//om        ms///+m   d///////oyhmN                                                               
          N+//yN       ms////+N    h////////////oym                                                         
          s//h       ho/+///sN     N///////////////od                                                          
         N+/h     my++yh+//y       s/////////////////oN                                                        
         Ns/m Nmy++ymNh//+d        s//////////////////+m                                                       
          NhssoshN  Ny//sN         m///////////////////+                                                       
                  Nmo/+ohdmN        mo//////////////////h            NmmN                                      
              ms/+s//o/-----:+sdN     mhso+ooys/////////o      mhs+/------/ohN                                 
    Nhd     N+-/o+/o+------------/shN     Ndy+//////////+ mhs+:---------------om                               
  mo/sN    m:/oo/oo:-----------------:://////////////////-----------------------y                              
  y//d    Noo++o+:----------:------------:://///////////:-------:/+osyso/:-------h                             
  Nyo+syysooo+/--------------::--------------:://///////:----::////+ossyso/------:                             
     NNNNNs--------------------:/::-------------:://///:-:://////////oosyo+:------                             
          y---------------------:////:::-----------:////////////////+o++++/:-----/                             
          m-----------------------://////////////////////////////+so/--:---------y                             
           +------------------------://////////////////////////+yy:---+oh/--:y+-/N                             
           N/-------------------------://////////////////////ohy/-------yy--os-/m                              
            No--------------------------://///////////////+shs/---------/d++/-oN                               
              mo--------------------------:////////////+shyo:------------sy/sm                                 
                Ny+:------------------------::://///oyhyo:--------------/sd                                    
                    mhso+/:------------------:/+oyhyo/----------:/+syhm                                        
                           NmddhyyyssssyyyhdmmNNNmhhhyyyyhhddmN                                                
</pre>

## Authors

<pre>
Luis Alvarez-Ruso [4] < Luis.Alvarez \at ific.uv.es >, 
Costas Andreopoulos (*) [7,10] < constantinos.andreopoulos \at cern.ch >, 
Adi Ashkenazi [8] < adishka \at gmail.com >, 
Christopher Barry [7] < C.Barry \at liverpool.ac.uk >, 
Steve Dennis [7] < s.r.dennis \at liverpool.ac.uk >, 
Steve Dytman [9] < dytman \at pitt.edu >, 
Hugh Gallagher [11] < hugh.gallagher \at tufts.edu >, 
Alfonso Andres Garcia Soto [3,4]  < aagarciasoto \at km3net.de >,
Steven Gardiner[2] < gardiner \at fnal.gov >, 
Walter Giele [2] < giele \at fnal.gov >, 
Robert Hatcher [2] < rhatcher \at fnal.gov >, 
Or Hen [8] < hen \at mit.edu >, 
Timothy Hobbs [2] < thobbs \at fnal.gov >, 
Libo Jiang [9] < libojiang8584 \at gmail.com >, 
Rhiannon Jones [7] < rhiannon.jones \at liverpool.ac.uk >, 
Igor Kakorin [6] < idkakorin \at gmail.com >, 
Konstantin Kuzmin [5,6] < kkuzmin \at theor.jinr.ru >, 
Anselmo Meregaglia [1] < anselmo.meregaglia \at cern.ch >, 
Donna Naples [9], 
Vadim Naumov [6] < vnaumov \at theor.jinr.ru >,  
Afroditi Papadopoulou [8] < apapadop \at mit.edu >, 
Gabriel Perdue [2] < perdue \at fnal.gov >, 
Marco Roda [7]  < marco.roda \at liverpool.ac.uk >, 
Noah Steinberg [2],  
Vladyslav Syrotenko [11]  < Vladyslav.Syrotenko \at tufts.edu >, 
Júlia Tena Vidal [7]  < j.tena-vidal \at liverpool.ac.uk >, 
Jeremy Wolcott [11]  < jwolcott \at fnal.gov >, 
Natalie Wright [8], and 
Julia Yarba [2]  < yarba_j \at fnal.gov >

(The GENIE Collaboration)

(1) CENBG, Université de Bordeaux, CNRS/IN2P3, 33175 Gradignan, France
(2) Fermi National Accelerator Laboratory, Batavia, Illinois 60510, USA
(3) Harvard University, Dept. of Physics, Cambridge, MA 02138, USA
(4) Instituto de Física Corpuscular (IFIC), Consejo Superior de Investigaciones Científicas (CSIC) y de la Universitat de Valéncia (UV), 46980, Paterna, Valéncia, Spain
(5) Alikhanov Institute for Theoretical and Experimental Physics (ITEP) of NRC "Kurchatov Institute", Moscow, 117218, Russia 
(6) Joint Institute for Nuclear Research (JINR), Dubna, Moscow region, 141980, Russia
(7) University of Liverpool, Dept. of Physics, Liverpool L69 7ZE, UK 
(8) Massachusetts Institute of Technology, Dept. of Physics, Cambridge, MA 02139, USA
(9) University of Pittsburgh, Dept. of Physics and Astronomy, Pittsburgh PA 15260, USA
(10) STFC Rutherford Appleton Laboratory, Particle Physics Dept., Harwell Oxford Campus, Oxfordshire OX11 0QX, UK
(11) Tufts University, Dept. of Physics and Astronomy, Medford MA 02155, USA

--------------------
(*) Corresponding Author:

 Prof. Costas Andreopoulos < constantinos.andreopoulos \at cern.ch >
    
 University of Liverpool          |  U.K. Research & Innovation (UKRI)
 Faculty of Science & Engineering |  Science & Technology Facilities Council (STFC)
 School of Physical Sciences      |  Rutherford Appleton Laboratory 
 Department of Physics            |  Particle Physics Department
 Oliver Lodge Lab 316             |  Harwell Oxford Campus, R1 2.89
 Liverpool L69 7ZE, UK            |  Oxfordshire OX11 0QX, UK          
 tel: +44-(0)1517-943201          |  tel: +44-(0)1235-445091 
</pre>
 

## Copyright

Copyright (c) 2003-2022, The GENIE Collaboration. For information, visit http://copyright.genie-mc.org 


## Physics & User manual

For installation and usage information, as well as information on the GENIE framework, event generator modules and tuning, 
see the GENIE Physics & User Manual in the public section of the GENIE Document Database:
https://genie-docdb.pp.rl.ac.uk/cgi-bin/ShowDocument?docid=2


## Public releases and physics tunes

For a list of public releases and a summary information, see http://releases.genie-mc.org

For a list of model configurations and tunes supported in each release, see http://tunes.genie-mc.org

The naming conventions for releases, model configurations and tunes are outlined in the GENIE web page and in the Physics & User manual.


## Contribution guidelines

GENIE welcomes community contributions through its Incubator. An Incubator Project is the unique route for any physics or software development into any of the GENIE suite products (Generator, Comparisons, Tuning). Details on the Incubator Project Phases (Launch, Research and Development, Graduation, Integration and Deployment) can be found in the GENIE Bylaws in the public section of the GENIE Document Database: https://genie-docdb.pp.rl.ac.uk/cgi-bin/ShowDocument?docid=1


## Citing GENIE

If you use GENIE, please **always** cite the following reference: 

<pre>
@article{Andreopoulos:2009rq,
      author         = "Andreopoulos, C. and others",
      title          = "{The GENIE Neutrino Monte Carlo Generator}",
      journal        = "Nucl. Instrum. Meth.",
      volume         = "A614",
      year           = "2010",
      pages          = "87-104",
      doi            = "10.1016/j.nima.2009.12.009",
      eprint         = "0905.2517",
      archivePrefix  = "arXiv",
      primaryClass   = "hep-ph",
      reportNumber   = "FERMILAB-PUB-09-418-CD",
      SLACcitation   = "%%CITATION = ARXIV:0905.2517;%%"
}
</pre>

If you used any of the standard GENIE applications, built-in flux and geometry drivers, or if you used any of its event reweightng and error propagation tools, please **add the following reference**:
<pre>
@article{Andreopoulos:2015wxa,
      author         = "Andreopoulos, Costas and Barry, Christopher and Dytman,
                        Steve and Gallagher, Hugh and Golan, Tomasz and Hatcher,
                        Robert and Perdue, Gabriel and Yarba, Julia",
      title          = "{The GENIE Neutrino Monte Carlo Generator: Physics and
                        User Manual}",
      year           = "2015",
      eprint         = "1510.05494",
      archivePrefix  = "arXiv",
      primaryClass   = "hep-ph",
      reportNumber   = "FERMILAB-FN-1004-CD",
      SLACcitation   = "%%CITATION = ARXIV:1510.05494;%%"
}
</pre>

Finally, if you used any of the new model configurations and tunes provided in the GENIE v3* series, please consider adding any of the following references is relevant:

<pre>
@article{GENIE:2021npt,
    author = "Alvarez-Ruso, Luis and others",
    collaboration = "GENIE",
    title = "{Recent highlights from GENIE v3}",
    eprint = "2106.09381",
    archivePrefix = "arXiv",
    primaryClass = "hep-ph",
    reportNumber = "FERMILAB-PUB-21-266-SCD-T",
    doi = "10.1140/epjs/s11734-021-00295-7",
    journal = "Eur. Phys. J. ST",
    volume = "230",
    number = "24",
    pages = "4449--4467",
    year = "2021"
}
</pre>

<pre>
@article{GENIE:2021zuu,
    author = "Tena-Vidal, J\'ulia and others",
    collaboration = "GENIE",
    title = "{Neutrino-nucleon cross-section model tuning in GENIE v3}",
    eprint = "2104.09179",
    archivePrefix = "arXiv",
    primaryClass = "hep-ph",
    reportNumber = "FERMILAB-PUB-20-531-SCD-T",
    doi = "10.1103/PhysRevD.104.072009",
    journal = "Phys. Rev. D",
    volume = "104",
    number = "7",
    pages = "072009",
    year = "2021"
}
</pre>

<pre>
@article{GENIE:2021wox,
    author = "Tena-Vidal, J\'ulia and others",
    collaboration = "GENIE",
    title = "{Hadronization model tuning in genie v3}",
    eprint = "2106.05884",
    archivePrefix = "arXiv",
    primaryClass = "hep-ph",
    reportNumber = "FERMILAB-PUB-21-024-QIS-SCD-T",
    doi = "10.1103/PhysRevD.105.012009",
    journal = "Phys. Rev. D",
    volume = "105",
    number = "1",
    pages = "012009",
    year = "2022"
}
</pre>

Please notice that the GENIE authors endorse the **MCNET guidelines for fair academic use** which can be found in http://www.montecarlonet.org/GUIDELINES. We invite users to consider which GENIE components are important for a particular analysis and cite them, in addition to the main references. A list of such references in maintained in the official GENIE web page.
