var
  a:array[1..20] of longint;
  v:array[1..20] of boolean;
  x,s,i,j,n,m,k,p,ans:longint;
begin
  p:=0;
  while true do
    begin
      readln(n,m,k);
      if n=0 then break;
      inc(p);
      writeln('Sequence ',p);
      for i:=1 to n do readln(a[i]);
      fillchar(v,sizeof(v),false);
      ans:=0;
      x:=0;
      for i:=1 to m do
        begin
          readln(j);
          if v[j] then dec(x,a[j]) else inc(x,a[j]);
          v[j]:=not v[j];
          if ans<x then ans:=x;
          if x>k then break;
        end;
      if x>k then writeln('Fuse was blown.') else
        begin
          writeln('Fuse was not blown.');
          writeln('Maximal power consumption was ',ans,' amperes.');
        end;
      writeln;
    end;
end.