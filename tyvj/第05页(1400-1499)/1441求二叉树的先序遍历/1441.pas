var
  s1,s2:string;
procedure init;
begin
  readln(s1);
  readln(s2);
end;
procedure find(a,b:string);
var
  s,L:longint;
begin
  L:=length(b);
  if L=1 then write(b)
    else
      begin
        write(b[L]);
        s:=pos(b[L],a);
        if s-1>0 then find(copy(a,1,s-1),copy(b,1,s-1));
        if L-s>0 then find(copy(a,s+1,L-s),copy(b,s,L-s));
      end;
end;
begin
  init;
  find(s1,s2);
end.