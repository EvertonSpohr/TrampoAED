#ifndef MODELCONFIG_H_INCLUDED
#define MODELCONFIG_H_INCLUDED

    //=======================

    float Valor_Multa;

    /**
    M�todo para ler as configuracoes do arquivo

    Pr�-Cond: configuracoes
    P�s-Cond: arquivo contendo as configs
    */
    void Ler_Config();

    /**
    M�todo para ler as configuracoes do arquivo

    Pr�-Cond: arquivo contendo as configuracoes
    P�s-Cond: configuracoes carregadas
    */
    void Salvar_Config();

#endif // MODELCONFIG_H_INCLUDED
