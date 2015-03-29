var
  n,k,p,q,ans:longint;
begin
  while not eof do
    begin
      readln(n,k);
      ans:=n;
      p:=ans div k;
      q:=ans mod k;
      while p>0 do
        begin
          ans:=ans+p;
          q:=q+p;
          p:=q div k;
          q:=q mod k;
        end;
      writeln(ans);
    end;
end.