# GRAMMAR GENERATOR

Fuzzer with AI
    ->  Select target
    ->  Instruct AI to generate grmmars(give some examples)
    ->  Having candidates of greammars, second getting the output of the grammar(*) -> score the output of grammar(Maybe need to modify the metrics of grmmar)
    ->  Recurisvely the enhence the grammar to make it forcus on specifications 
    ->  Fuzzing

Pros:
    Could a balance between efficiency and flexibility, faster than purely AI-generated methods and more convenient than purely grammar-based fuzzing.
Cons:
    Only suitable for simple syntaxes like HTML or JSON, not applicable to complex syntaxes like C.