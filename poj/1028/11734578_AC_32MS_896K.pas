var
  b,f:array[0..101] of string;
  s:string;
  i,j,k:longint;
begin
  i:=0;
  b[0]:='http://www.acm.org/';
  j:=0;
  while true do
    begin
      readln(s);
      case s[1] of
        'V':begin
              inc(i);
              delete(s,1,pos(' ',s));
              b[i]:=s;
              writeln(s);
              j:=0;
            end;
        'B':if i>0 then
              begin
                inc(j);
                f[j]:=b[i];
                writeln(b[i-1]);
                dec(i);
              end
            else writeln('Ignored');
        'F':if j>0 then
              begin
                inc(i);
                b[i]:=f[j];
                writeln(f[j]);
                dec(j);
              end
            else writeln('Ignored');
        'Q':break;
      end;
    end;
end.