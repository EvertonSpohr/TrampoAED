#ifndef MODELCONFIG_H_INCLUDED
#define MODELCONFIG_H_INCLUDED

    //=======================

    float Valor_Multa;

    /**
    Método para ler as configuracoes do arquivo

    Pré-Cond: configuracoes
    Pós-Cond: arquivo contendo as configs
    */
    void Ler_Config();

    /**
    Método para ler as configuracoes do arquivo

    Pré-Cond: arquivo contendo as configuracoes
    Pós-Cond: configuracoes carregadas
    */
    void Salvar_Config();

#endif // MODELCONFIG_H_INCLUDED
